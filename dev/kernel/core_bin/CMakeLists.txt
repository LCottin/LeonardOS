# Linker script file path
set(CORE_LINKER_SCRIPT ${CORE_BIN_DIR}/linker.ld)

# Specify the source file
set(CORE_SOURCES
    ${KERNEL_DIR}/boot/src/boot.s
    ${KERNEL_DIR}/MMIO/io8/src/MMIO_io8.c
    ${KERNEL_DIR}/MMIO/io16/src/MMIO_io16.c
    ${KERNEL_DIR}/MMIO/io32/src/MMIO_io32.c
    ${KERNEL_DIR}/MMIO/io64/src/MMIO_io64.c
    ${KERNEL_DIR}/serial/src/serial.c
    ${KERNEL_DIR}/UART/src/UART.c
    ${CORE_DIR}/main.c
)

set(CORE_HEADERS
    ${KERNEL_DIR}/MMIO/io8/include/MMIO_io8.h
    ${KERNEL_DIR}/MMIO/io16/include/MMIO_io16.h
    ${KERNEL_DIR}/MMIO/io32/include/MMIO_io32.h
    ${KERNEL_DIR}/MMIO/io64/include/MMIO_io64.h
    ${KERNEL_DIR}/serial/include/serial.h
    ${KERNEL_DIR}/UART/include/UART.h
)

# Specify the public header directory
set(CORE_INCLUDE
    ${KERNEL_DIR}/MMIO/io8/include
    ${KERNEL_DIR}/MMIO/io16/include
    ${KERNEL_DIR}/MMIO/io32/include
    ${KERNEL_DIR}/MMIO/io64/include
    ${KERNEL_DIR}/serial/include
    ${KERNEL_DIR}/UART/include
)

set(CORE_INCLUDE_PRV
    ${KERNEL_DIR}/UART/src
)

# Add an executable target
add_executable(${CORE_NAME} ${CORE_SOURCES})

# Link header files
target_include_directories(${CORE_NAME}
    PUBLIC ${CORE_INCLUDE}
    PRIVATE ${CORE_INCLUDE_PRV}
)

# Ensure the executable is built after the library
add_dependencies(${CORE_NAME} ${LIB_MEMORY_NAME})
add_dependencies(${CORE_NAME} ${LIB_STRING_NAME})

# Link the common library
target_link_libraries(${CORE_NAME} -Wl,--whole-archive ${LIB_MEMORY_NAME} ${LIB_STRING_NAME})

# Set custom linker options, including the generation of the .map file
target_link_options(${CORE_NAME} PRIVATE
                    "-T${CORE_LINKER_SCRIPT}"
                    "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CORE_NAME}.map")

