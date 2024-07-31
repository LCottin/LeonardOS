# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Set the target architecture
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Ensure objcopy is found and set for binary conversion
find_program(CMAKE_OBJCOPY aarch64-none-elf-objcopy REQUIRED)

# Specify the cross-compiler tools
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_COMPILER   clang)

# Specify the flags for Clang
set(CMAKE_ASM_FLAGS "-target aarch64-none-elf -march=armv8-a")
set(CMAKE_C_FLAGS   "-target aarch64-none-elf -ffreestanding -nostdlib")

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_NAME "LeonardOS")

# Project name and version
project(LeonardOS LANGUAGES ASM C)

    # Define directories
    set(DEV_DIR ${CMAKE_SOURCE_DIR}/dev)

    # Linker script file path
    set(LINKER_SCRIPT ${DEV_DIR}/linker.ld)

    # Specify the source file
    set(SOURCES
        ${DEV_DIR}/bootloader/src/boot.s
        ${DEV_DIR}/kernelPrint/src/kernelPrint.c
        ${DEV_DIR}/UART/src/UART.c
        ${DEV_DIR}/main.c)

    # Specify the public header file
    set(HEADERS
        ${DEV_DIR}/kernelPrint/include
        ${DEV_DIR}/UART/include)

    # Add an executable target
    add_executable(${EXECUTABLE_NAME} ${SOURCES})

    # Link header file
    target_include_directories(${EXECUTABLE_NAME} PRIVATE ${HEADERS})

    # Set custom assembler and linker flags
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES
                            LINK_FLAGS "-T${LINKER_SCRIPT}")

    # Add a custom target to create the binary image
    add_custom_target(elf_to_bin ALL
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE_NAME}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EXECUTABLE_NAME}.img
        DEPENDS ${EXECUTABLE_NAME}
        COMMENT "Converting ELF to binary image")
