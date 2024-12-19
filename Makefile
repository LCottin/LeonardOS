# Compiler and build settings
BUILD_DIR = build
BIN_DIR   = $(BUILD_DIR)/bin
CORE_ELF  = $(BIN_DIR)/core/core.elf

# Targets that don't represent real files
.PHONY: all build prepare clean deep_clean install debug run_debug run run_el1 run_el2 run_el3

# Install dependencies
install:
	./install_dependencies.bash

# Run all the commands
all: clean build

# Create the build directory, configure, and build the project
build: prepare
	@echo "Building project ..."
	@$(MAKE) -C $(BUILD_DIR)

# Configure the project (run CMake if necessary)
prepare:
	@echo "Configuring project ..."
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)

# Clean only the compiled objects in the build directory
clean:
	@echo "Cleaning binaries ..."
	@$(MAKE) -C $(BUILD_DIR) clean
	@rm -rf $(BIN_DIR)/*

# Completely remove the build directory
deep_clean:
	@echo "Removing build directory ..."
	@rm -rf $(BUILD_DIR)/*

# Launch GDB to debug the system
debug:
	@if ! command -v aarch64-none-elf-gdb >/dev/null 2>&1; then \
		echo "Error: aarch64-none-elf-gdb not found."; \
		exit 1; \
	fi
	aarch64-none-elf-gdb $(CORE_ELF)

# Run the OS using QEMU in debug mode
run_debug: build
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64 -M virt -m 512M -cpu cortex-a53 -nographic -kernel $(CORE_ELF) -serial mon:stdio  -s -S -d int &

# Run the OS using QEMU
run:
	@make run_el1

run_el1: build
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64 -M virt -m 512M -cpu cortex-a53 -nographic -kernel $(CORE_ELF) -serial mon:stdio &

run_el2: build
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64 -M virt -m 512M -cpu cortex-a53 -nographic -kernel $(CORE_ELF) -serial mon:stdio -machine virtualization=on &

run_el3: build
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64 -M virt -m 512M -cpu cortex-a53 -nographic -kernel $(CORE_ELF) -serial mon:stdio -machine virtualization=on -machine secure=on &

# Kill all QEMU instances
kill:
	@echo "Killing all QEMU instances ..."
	@pkill -9 qemu
