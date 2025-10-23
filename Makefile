# Compiler and build settings
ROOT_DIR  = $(shell pwd)
BUILD_DIR = $(ROOT_DIR)/build
DEBUG_DIR = $(ROOT_DIR)/debug
TOOLS_DIR = $(ROOT_DIR)/tools
TESTS_DIR = $(ROOT_DIR)/tests
VERBOSE?=0

# Binary names
BOOT_ELF_NAME        = boot_bin
CORE_ELF_NAME        = core_bin
HELLO_WORLD_ELF_NAME = hello_world
COUNT_DOWN_ELF_NAME  = count_down

BIN_DEV_DIR         = $(BUILD_DIR)/bin/dev
BIN_TESTS_DIR       = $(BUILD_DIR)/bin/tests
BOOT_ELF_DIR        = $(BIN_DEV_DIR)/$(BOOT_ELF_NAME)/$(BOOT_ELF_NAME).elf
CORE_ELF_DIR        = $(BIN_DEV_DIR)/$(CORE_ELF_NAME)/$(CORE_ELF_NAME).elf
HELLO_WORLD_ELF_DIR = $(BIN_DEV_DIR)/$(HELLO_WORLD_ELF_NAME)/$(HELLO_WORLD_ELF_NAME).elf
COUNT_DOWN_ELF_DIR  = $(BIN_DEV_DIR)/$(COUNT_DOWN_ELF_NAME)/$(COUNT_DOWN_ELF_NAME).elf

PRE_OS_IMG      = $(BUILD_DIR)/bin/preOS.img
LEONARD_OS_IMG  = $(BIN_DEV_DIR)/LeonardOS.img
DEBUG_SCRIPT    = $(DEBUG_DIR)/run_debug.gdb

SCRIPTS_DIR         = $(TOOLS_DIR)/scripts
TESTS_FRAMEWORk_DIR = $(TOOLS_DIR)/test_framework

include Makefile.build
include Makefile.run
include Makefile.test

# Configure the project (run CMake if necessary)
.PHONY: prepare
prepare:
	@echo "Configuring project in $(ROOT_DIR)..."
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)
	@make memory_mapping
	@rm -f $(PRE_OS_IMG)
	@dd if=/dev/zero of=$(PRE_OS_IMG) bs=1024 count=16384

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

# Kill all QEMU instances
.PHONY: kill
kill:
	@echo "Killing all QEMU instances ..."
	@pkill -9 qemu || true
