# Compiler and build settings
BUILD_DIR  = build
KERNEL_IMG = $(BUILD_DIR)/bin/LeonardOS

# Targets that don't represent real files
.PHONY: all build clean deep_clean run install

# Install dependencies
install:
	./install_dependencies.bash

# Run all the commands
all: clean build

# Create the build directory, configure, and build the project
build: $(BUILD_DIR)/Makefile
	@$(MAKE) -C $(BUILD_DIR)

# Configure the project (run CMake if necessary)
$(BUILD_DIR)/Makefile:
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)

# Clean only the compiled objects in the build directory
clean:
	@$(MAKE) -C $(BUILD_DIR) clean

# Completely remove the build directory
deep_clean:
	@rm -rf $(BUILD_DIR)

# Run the OS using QEMU
run: build
	@if ! command -v qemu-system-aarch64 >/dev/null 2>&1; then \
		echo "Error: qemu-system-aarch64 not found."; \
		exit 1; \
	fi
	@qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -kernel $(KERNEL_IMG) -serial mon:stdio
