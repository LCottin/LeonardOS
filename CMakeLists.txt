### find our os (wins, centos, ubuntu, etc)
set(VAR_OS "")
IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(DEBUG "Linux")
    execute_process (
            COMMAND bash -c "awk -F= '/^ID=/{print $2}' /etc/os-release |tr -d '\n' | tr -d '\"'"
            OUTPUT_VARIABLE VAR_OS
    )
    MESSAGE(DEBUG "Linux os: ${VAR_OS}")
ELSEIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(DEBUG "Windows")
    set(VAR_OS "wins")
ELSEIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(DEBUG "Windows")
    set(VAR_OS "mac")
ELSE()
    MESSAGE(FATAL " No OS detected!")
ENDIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")

message("-- OS: ${VAR_OS}")

# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Set the target architecture
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Specify the cross-compiler tools
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_COMPILER   clang)

# Specify the flags for Clang
set(CMAKE_ASM_FLAGS "-target aarch64-none-elf -g -march=armv8-a -mtune=cortex-a53 -nostdlib")
set(CMAKE_C_FLAGS   "-target aarch64-none-elf -g -march=armv8-a -mtune=cortex-a53 -std=c17 -ffreestanding -nostdlib")

# Specify the linker
set(CMAKE_LINKER aarch64-none-elf-ld)

# Use the appropriate archiver and ranlib for ARM64
set(CMAKE_AR aarch64-none-elf-ar)
set(CMAKE_RANLIB aarch64-none-elf-ranlib)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find tool to convert elf to binary
find_program(CMAKE_OBJCOPY aarch64-none-elf-objcopy REQUIRED)

# Project name and version
project(${IMG_NAME} LANGUAGES ASM C)

    enable_language(ASM)

    # Define directories
    set(KERNEL_DIR ${CMAKE_SOURCE_DIR}/dev/kernel)

    # Call subdirectories cmake
    add_subdirectory(${KERNEL_DIR})
