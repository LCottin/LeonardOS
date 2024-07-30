# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Set the target architecture
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Ensure objcopy is found and set for binary conversion
find_program(CMAKE_OBJCOPY aarch64-none-elf-objcopy)

# Specify the cross-compiler tools
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_COMPILER   clang)

# Specify the flags for Clang
set(CMAKE_ASM_FLAGS "-target aarch64-none-elf -march=armv8-a")
set(CMAKE_C_FLAGS   "-target aarch64-none-elf -ffreestanding -nostdlib")

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Project name and version
project(LeonardOS LANGUAGES ASM C)

    # Define directories
    set(DEV_DIR ${CMAKE_SOURCE_DIR}/dev)

    # Linker script file path
    set(LINKER_SCRIPT ${DEV_DIR}/linker.ld)

    # Specify the source file
    set(SOURCES ${DEV_DIR}/bootloader/src/boot.s
                ${DEV_DIR}/main.c)

    # Add an executable target
    add_executable(bootloader ${SOURCES})

    # Set custom assembler and linker flags
    set_target_properties(bootloader PROPERTIES
                            LINK_FLAGS "-nostdlib -T${LINKER_SCRIPT}")

    # Add a custom target to create the binary image
    add_custom_target(elf_to_bin ALL
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:bootloader> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bootloader.img
        DEPENDS bootloader
        COMMENT "Converting ELF to binary image")
