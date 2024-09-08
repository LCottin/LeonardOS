# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Set the target architecture
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Specify the cross-compiler tools
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_COMPILER   clang)

# Specify the flags for Clang
set(CMAKE_ASM_FLAGS "-target aarch64-none-elf -march=armv8-a -mtune=cortex-a53")
set(CMAKE_C_FLAGS   "-target aarch64-none-elf -march=armv8-a -mtune=cortex-a53 -std=c17 -ffreestanding -nostdlib")

# Specify the linker
set(CMAKE_LINKER aarch64-none-elf-ld)

# Use the appropriate archiver and ranlib for ARM64
set(CMAKE_AR aarch64-none-elf-ar)
set(CMAKE_RANLIB aarch64-none-elf-ranlib)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(KERNEL_NAME     "LeonardOS")
set(LIB_COMMON_NAME "Common")

# Project name and version
project(${KERNEL_NAME} LANGUAGES ASM C)

    # Define directories
    set(CORE_DIR   ${CMAKE_SOURCE_DIR}/dev/core)
    set(COMMON_DIR ${CMAKE_SOURCE_DIR}/dev/common)

    # Call subdirectories cmake
    add_subdirectory(${COMMON_DIR})
    add_subdirectory(${CORE_DIR})
