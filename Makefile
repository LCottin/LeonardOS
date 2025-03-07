# Compiler and build settings
BUILD_DIR = build
DEBUG_DIR = debug
TOOLS_DIR = tools

BIN_DIR        = $(BUILD_DIR)/bin
BOOT_BIN       = $(BIN_DIR)/boot/boot.bin
BOOT_ELF       = $(BIN_DIR)/boot/boot.elf
CORE_BIN       = $(BIN_DIR)/core/core.bin
CORE_ELF       = $(BIN_DIR)/core/core.elf
LEONARD_OS_IMG = $(BIN_DIR)/LeonardOS.img
DEBUG_SCRIPT   = $(DEBUG_DIR)/run_debug.gdb

SCRIPTS_DIR = $(TOOLS_DIR)/scripts

# Install dependencies
install:
	./install_dependencies.bash

# Run all the commands
all: clean build

# Create the build directory, configure, and build the project
build: prepare
	@echo "Building project ..."
	@$(MAKE) -C $(BUILD_DIR) --no-print-directory

# Rebuild the project
rebuild:
	@make clean
	@make build

# Create the image file for the OS
image: build
	@rm -f $(LEONARD_OS_IMG)
	@dd if=/dev/zero of=$(LEONARD_OS_IMG) bs=512 count=32768
	@dd if=$(CORE_ELF) of=$(LEONARD_OS_IMG) bs=1 seek=5242880 conv=notrunc

# Configure the project (run CMake if necessary)
prepare:
	@echo "Configuring project ..."
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)
	@make memory_mapping

# Clean only the compiled objects in the build directory
clean:
	@echo "Cleaning binaries ..."
	@$(MAKE) -C $(BUILD_DIR) clean --no-print-directory
	@rm -rf $(BIN_DIR)/*

# Completely remove the build directory
deep_clean:
	@echo "Removing build directory ..."
	@rm -rf $(BUILD_DIR)/*

# Generate the memory mapping
memory_mapping:
	@echo "Generating memory mapping ..."
	@python3 $(SCRIPTS_DIR)/generate_memory_mapping.py

# Launch GDB to debug the system
debug:
	@if ! command -v aarch64-none-elf-gdb >/dev/null 2>&1; then \
		echo "Error: aarch64-none-elf-gdb not found."; \
		exit 1; \
	fi
	@aarch64-none-elf-gdb 			\
		-ex "file $(BOOT_ELF)" 		\
		-ex "source $(DEBUG_SCRIPT)"

# Run the OS using QEMU in debug mode
run_debug:
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64 										\
	-M virt 													\
	-m 512M 													\
	-cpu cortex-a53 											\
	-nographic 													\
	-kernel $(BOOT_ELF) 										\
	-serial mon:stdio											\
	-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
	-no-reboot 													\
	-s -S -d int,unimp,guest_errors &							\

# Run the OS using QEMU
run:
	@make run_el1

# Run the OS using QEMU in EL1
run_el1:
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64											\
		-M virt														\
		-m 512M														\
		-cpu cortex-a53												\
		-nographic													\
		-kernel $(BOOT_ELF)											\
		-serial mon:stdio 											\
		-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
		-no-reboot &

# Run the OS using QEMU in EL2
run_el2:
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64											\
		-M virt														\
		-m 512M														\
		-cpu cortex-a53												\
		-nographic													\
		-kernel $(BOOT_ELF)											\
		-serial mon:stdio 											\
		-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
		-no-reboot													\
		-machine virtualization=on &

# Run the OS using QEMU in EL3
run_el3:
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64											\
		-M virt														\
		-m 512M														\
		-cpu cortex-a53												\
		-nographic													\
		-kernel $(BOOT_ELF)											\
		-serial mon:stdio 											\
		-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
		-no-reboot													\
		-machine virtualization=on									\
		-machine secure=on &

# Kill all QEMU instances
kill:
	@echo "Killing all QEMU instances ..."
	@pkill -9 qemu || true
