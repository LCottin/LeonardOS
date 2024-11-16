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
set(CMAKE_ASM_FLAGS "-target aarch64-none-elf -g -march=armv8-a -mtune=cortex-a53")
set(CMAKE_C_FLAGS   "-target aarch64-none-elf -g -march=armv8-a -mtune=cortex-a53 -std=c17 -ffreestanding -nostdlib")

IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    IF(VAR_OS MATCHES "ubuntu")
        # Specify the linker
        set(CMAKE_LINKER arm-none-eabi-ld)

        # Use the appropriate archiver and ranlib for ARM64
        set(CMAKE_AR arm-none-eabi-ar)
        set(CMAKE_RANLIB arm-none-eabi-ranlib)
    ELSE()
        # Specify the linker
        set(CMAKE_LINKER aarch64-none-elf-ld)

        # Use the appropriate archiver and ranlib for ARM64
        set(CMAKE_AR aarch64-none-elf-ar)
        set(CMAKE_RANLIB aarch64-none-elf-ranlib)
    ENDIF(VAR_OS MATCHES "ubuntu")
ELSEIF(CMAKE_HOST_SYSTEM_NAME MATCHES "mac")
    # Specify the linker
    set(CMAKE_LINKER aarch64-none-elf-ld)

    # Use the appropriate archiver and ranlib for ARM64
    set(CMAKE_AR aarch64-none-elf-ar)
    set(CMAKE_RANLIB aarch64-none-elf-ranlib)
ENDIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(KERNEL_NAME      "LeonardOS")
set(LIB_MEMORY_NAME  "Memory")
set(LIB_STRING_NAME  "String")
set(LIB_SYSCALL_NAME "Syscall")

# Project name and version
project(${KERNEL_NAME} LANGUAGES ASM C)

    # Define directories
    set(CORE_DIR ${CMAKE_SOURCE_DIR}/dev/kernel/core)
    set(LIB_DIR  ${CMAKE_SOURCE_DIR}/dev/kernel/lib)

    # Call subdirectories cmake
    add_subdirectory(${LIB_DIR})
    add_subdirectory(${CORE_DIR})

    # Add a custom target to create the binary image
    add_custom_target(elf_to_bin ALL
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${KERNEL_NAME}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${KERNEL_NAME}.img
    DEPENDS ${LIB_SYSCALL_NAME} ${KERNEL_NAME}
    COMMENT "Converting ELF to binary image")
