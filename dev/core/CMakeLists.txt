# Linker script file path
set(LINKER_SCRIPT ${CORE_DIR}/linker.ld)

# Specify the source file
set(SOURCES
    ${CORE_DIR}/bootloader/src/boot.s
    ${CORE_DIR}/kernelPrint/src/kernelPrint.c
    ${CORE_DIR}/UART/src/UART.c
    ${CORE_DIR}/main.c)

# Specify the public header file
set(HEADERS
    ${CORE_DIR}/kernelPrint/include
    ${CORE_DIR}/UART/include)

# Add an executable target
add_executable(${KERNEL_NAME} ${SOURCES})

# Link header file
target_include_directories(${KERNEL_NAME} PRIVATE ${HEADERS})

# Set custom assembler and linker flags
set_target_properties(${KERNEL_NAME} PROPERTIES
                        LINK_FLAGS "-T${LINKER_SCRIPT}")

# Add a custom target to create the binary image
add_custom_target(elf_to_bin ALL
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${KERNEL_NAME}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${KERNEL_NAME}.img
    DEPENDS ${KERNEL_NAME}
    COMMENT "Converting ELF to binary image")
