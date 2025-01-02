# Set the output directory of the executable
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CORE_NAME})

# Linker script file path
set(CORE_LINKER_SCRIPT ${CORE_BIN_DIR}/linker.ld)

# Set the name of the executable
SET(CORE_NAME_ELF      ${CORE_NAME}.elf)
SET(CORE_NAME_BIN      ${CORE_NAME}.bin)
SET(CORE_NAME_MAP      ${CORE_NAME}.map)
SET(CORE_NAME_STRIPPED ${CORE_NAME}.elf.stripped)

# Specify the source file
set(CORE_SOURCES
    ${KERNEL_DIR}/boot/src/boot.s
    ${KERNEL_DIR}/MMIO/io8/src/MMIO_io8.c
    ${KERNEL_DIR}/MMIO/io16/src/MMIO_io16.c
    ${KERNEL_DIR}/MMIO/io32/src/MMIO_io32.c
    ${KERNEL_DIR}/MMIO/io64/src/MMIO_io64.c
    ${KERNEL_DIR}/serial/src/serial.c
    ${KERNEL_DIR}/UART/src/UART.c
    ${KERNEL_DIR}/FPU/src/FPU_init.s
    ${CORE_DIR}/core_main.c
)

set(CORE_HEADERS
    ${KERNEL_DIR}/MMIO/io8/include/MMIO_io8.h
    ${KERNEL_DIR}/MMIO/io16/include/MMIO_io16.h
    ${KERNEL_DIR}/MMIO/io32/include/MMIO_io32.h
    ${KERNEL_DIR}/MMIO/io64/include/MMIO_io64.h
    ${KERNEL_DIR}/serial/include/serial.h
    ${KERNEL_DIR}/UART/include/UART.h
    ${KERNEL_DIR}/FPU/include/FPU.h
)

# Specify the public header directory
set(CORE_INCLUDE
    ${KERNEL_DIR}/MMIO/io8/include
    ${KERNEL_DIR}/MMIO/io16/include
    ${KERNEL_DIR}/MMIO/io32/include
    ${KERNEL_DIR}/MMIO/io64/include
    ${KERNEL_DIR}/serial/include
    ${KERNEL_DIR}/UART/include
    ${KERNEL_DIR}/FPU/include
)

set(CORE_INCLUDE_PRV
    ${KERNEL_DIR}/UART/src
)

# Add an executable target
add_executable(${CORE_NAME_ELF} ${CORE_SOURCES})

# Link header files
target_include_directories(${CORE_NAME_ELF}
    PUBLIC ${CORE_INCLUDE}
    PRIVATE ${CORE_INCLUDE_PRV}
)

# Ensure the executable is built after the library
add_dependencies(${CORE_NAME_ELF} ${LIB_MEMORY_NAME})
add_dependencies(${CORE_NAME_ELF} ${LIB_STRING_NAME})

# Link the common library
target_link_libraries(${CORE_NAME_ELF} -Wl,--whole-archive ${LIB_MEMORY_NAME} ${LIB_STRING_NAME})

# Set custom linker options, including the generation of the .map file
target_link_options(${CORE_NAME_ELF} PRIVATE
                    "-T${CORE_LINKER_SCRIPT}"
                    "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CORE_NAME_MAP}")

# Generate .bin, .elf.stripped and .map files
add_custom_command(
    TARGET ${CORE_NAME_ELF}
    POST_BUILD

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${CORE_NAME_ELF}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CORE_NAME_STRIPPED}

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CORE_NAME_ELF}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CORE_NAME_BIN}
)
