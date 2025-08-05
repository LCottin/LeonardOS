# Compiler and build settings
BUILD_DIR = build
DEBUG_DIR = debug
TOOLS_DIR = tools
VERBOSE?=0

# Binary names
BOOT_ELF_NAME        = boot_bin.elf
CORE_ELF_NAME        = core_bin.elf
HELLO_WORLD_ELF_NAME = hello_world.elf
COUNT_DOWN_ELF_NAME  = count_down.elf

BIN_DIR             = $(BUILD_DIR)/bin
BOOT_ELF_DIR        = $(BIN_DIR)/boot_bin/$(BOOT_ELF_NAME)
CORE_ELF_DIR        = $(BIN_DIR)/core_bin/$(CORE_ELF_NAME)
HELLO_WORLD_ELF_DIR = $(BIN_DIR)/hello_world/$(HELLO_WORLD_ELF_NAME)
COUNT_DOWN_ELF_DIR  = $(BIN_DIR)/count_down/$(COUNT_DOWN_ELF_NAME)

LEONARD_OS_IMG  = $(BIN_DIR)/LeonardOS.img
DEBUG_SCRIPT    = $(DEBUG_DIR)/run_debug.gdb

SCRIPTS_DIR = $(TOOLS_DIR)/scripts

# Install dependencies
.PHONY: install
install:
	./install_dependencies.bash

# Create a new component
.PHONY: component
component:
	@echo "Creating new component ..."
	@python3 $(SCRIPTS_DIR)/Component.py $(VERBOSE)

# Create a new sub component
.PHONY: sub_component
sub_component:
	@echo "Creating new sub component ..."
	@python3 $(SCRIPTS_DIR)/SubComponent.py $(VERBOSE)

# Create a new binary
.PHONY: binary
binary:
	@echo "Creating new binary ..."
	@python3 $(SCRIPTS_DIR)/Executable.py $(VERBOSE)

# Create a new application
.PHONY: application
application:
	@echo "Creating new application ..."
	@python3 $(SCRIPTS_DIR)/Application.py $(VERBOSE)

# Create the build directory, configure, and build core binary
.PHONY: build_core
build_core: prepare
	@echo "Building core ..."
	@$(MAKE) -C $(BUILD_DIR) --no-print-directory $(CORE_ELF_NAME)

# Create the build directory, configure, and build boot binary
.PHONY: build_boot
build_boot: prepare
	@echo "Building boot ..."
	@$(MAKE) -C $(BUILD_DIR) --no-print-directory $(BOOT_ELF_NAME)

# Create the build directory, configure, and build application binaries
.PHONY: build_app
build_app: prepare
	@echo "Building applications ..."
	@$(MAKE) -C $(BUILD_DIR) --no-print-directory applications

# Create the build directory, configure, and build all binaries
.PHONY: build_all
build_all: prepare
	@echo "Building project ..."
	@$(MAKE) -C $(BUILD_DIR) --no-print-directory

# Rebuild the project
.PHONY: rebuild
rebuild:
	@make clean
	@make build_all

# Create the image file for the OS
.PHONY: image
image: build_all
	@rm -f $(LEONARD_OS_IMG)
	@dd if=/dev/zero              of=$(LEONARD_OS_IMG) bs=512 count=32768
	@dd if=$(CORE_ELF_DIR)        of=$(LEONARD_OS_IMG) bs=1   seek=5242880 conv=notrunc
	@dd if=$(HELLO_WORLD_ELF_DIR) of=$(LEONARD_OS_IMG) bs=1   seek=7340032 conv=notrunc
	@dd if=$(COUNT_DOWN_ELF_DIR)  of=$(LEONARD_OS_IMG) bs=1   seek=7471104 conv=notrunc

# Configure the project (run CMake if necessary)
.PHONY: prepare
prepare:
	@echo "Configuring project ..."
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)
	@make memory_mapping

# Clean only the compiled objects in the build directory
.PHONY: clean
clean:
	@echo "Cleaning binaries ..."
	@$(MAKE) -C $(BUILD_DIR) clean --no-print-directory
	@rm -rf $(BIN_DIR)/*

# Completely remove the build directory
.PHONY: deep_clean
deep_clean:
	@echo "Removing build directory ..."
	@rm -rf $(BUILD_DIR)/*

# Generate the memory mapping
.PHONY: memory_mapping
memory_mapping:
	@echo "Generating memory mapping ..."
	@python3 $(SCRIPTS_DIR)/generate_memory_mapping.py

# Launch GDB to debug the system
.PHONY: debug
debug:
	@if ! command -v aarch64-none-elf-gdb >/dev/null 2>&1; then \
		echo "Error: aarch64-none-elf-gdb not found."; \
		exit 1; \
	fi
	@aarch64-none-elf-gdb 			\
		-ex "file $(BOOT_ELF_DIR)"	\
		-ex "source $(DEBUG_SCRIPT)"

# Run the OS using QEMU in debug mode
.PHONY: run_debug
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
	-kernel $(BOOT_ELF_DIR)										\
	-serial mon:stdio											\
	-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
	-no-reboot 													\
	-s -S -d int,unimp,guest_errors &							\

# Run the OS using QEMU
.PHONY: run
run:
	@make run_el1

# Run the OS using QEMU in EL1
.PHONY: run_el1
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
		-kernel $(BOOT_ELF_DIR)										\
		-serial mon:stdio 											\
		-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
		-no-reboot &

# Run the OS using QEMU in EL2
.PHONY: run_el2
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
		-kernel $(BOOT_ELF_DIR)										\
		-serial mon:stdio 											\
		-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
		-no-reboot													\
		-machine virtualization=on &

# Run the OS using QEMU in EL3
.PHONY: run_el3
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
		-kernel $(BOOT_ELF_DIR)										\
		-serial mon:stdio 											\
		-device loader,file=$(LEONARD_OS_IMG),addr=0x0				\
		-no-reboot													\
		-machine virtualization=on									\
		-machine secure=on &

# Kill all QEMU instances
.PHONY: kill
kill:
	@echo "Killing all QEMU instances ..."
	@pkill -9 qemu || true
