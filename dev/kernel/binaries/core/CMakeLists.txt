# ==============================================================================
# Set the binary name
# ==============================================================================
set(BIN_NAME ${BIN_NAME})
set(BIN_PATH ${BIN_PATH})

# ==============================================================================
# Set binary generation path
# ==============================================================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DEV_DIR}/${BIN_NAME})
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld)

# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(CORE_MAIN_DIR
    ${BIN_PATH}/code/main
)

set(CORE_MAIN_SOURCES
    # Add the path to each source file here
    ${CORE_MAIN_DIR}/src/core_main.c
)

set(CORE_MAIN_HEADERS
    ${CORE_MAIN_DIR}/inc
)

# ==============================================================================
# Create source and header for METADATA
# ==============================================================================
set(CORE_METADATA_DIR
    ${BIN_PATH}/code/metadata
)

set(CORE_METADATA_SOURCES
    # Add the path to each source file here
    ${CORE_METADATA_DIR}/src/core_metadata.c
)

set(CORE_METADATA_HEADERS
    ${CORE_METADATA_DIR}/inc
)

# ==============================================================================
# Create binary
# ==============================================================================
add_executable(${BIN_NAME}.elf
    ${CORE_MAIN_SOURCES}
    ${CORE_METADATA_SOURCES}
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${BIN_NAME}.elf
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_fpu
        arch.lib_irq
        arch.lib_seh
        arch.lib_types
        drivers.lib_console
        drivers.lib_gic
        drivers.lib_uart
        libraries.lib_formatter
        libraries.lib_metadata
        libraries.lib_stream
        libraries.lib_strings
        memory.lib_heap
        memory.lib_tools
        system.lib_bmt
        system.lib_clock
        system.lib_elf
        system.lib_pcb
        system.lib_printer
        system.lib_scheduler
)

# ==============================================================================
# Set custom linker options, including the generation of the .map file
# ==============================================================================
target_link_options(${BIN_NAME}.elf
    PRIVATE
        "-T${LINKER_SCRIPT}"
        "-Wl,--print-memory-usage,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.map"
)

# ==============================================================================
# Generate .bin and .elf.stripped files
# ==============================================================================
add_custom_command(
    TARGET
    ${BIN_NAME}.elf
    POST_BUILD

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${BIN_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.bin

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${BIN_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.elf.stripped
)
