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
# Create source and header for MEMORY
# ==============================================================================
set(BOOT_MEMORY_DIR
    ${BIN_PATH}/code/memory
)

set(BOOT_MEMORY_SOURCES
    # Add the path to each source file here
    ${BOOT_MEMORY_DIR}/src/boot_memory_parse.c
)

set(BOOT_MEMORY_HEADERS
    ${BOOT_MEMORY_DIR}/inc
)

# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(BOOT_MAIN_DIR
    ${BIN_PATH}/code/main
)

set(BOOT_MAIN_SOURCES
    # Add the path to each source file here
    ${BOOT_MAIN_DIR}/src/boot_main.c
)

set(BOOT_MAIN_HEADERS
    ${BOOT_MAIN_DIR}/inc
)

# ==============================================================================
# Create source and header for METADATA
# ==============================================================================
set(BOOT_METADATA_DIR
    ${BIN_PATH}/code/metadata
)

set(BOOT_METADATA_SOURCES
    # Add the path to each source file here
    ${BOOT_METADATA_DIR}/src/boot_metadata.c
)

set(BOOT_METADATA_HEADERS
    ${BOOT_METADATA_DIR}/inc
)

# ==============================================================================
# Create binary
# ==============================================================================
add_executable(${BIN_NAME}.elf
    ${BOOT_MEMORY_SOURCES}
    ${BOOT_MAIN_SOURCES}
    ${BOOT_METADATA_SOURCES}
)

# ==============================================================================
# Add binary include directories
# ==============================================================================
target_include_directories(${BIN_NAME}.elf
    PRIVATE
        ${BOOT_MEMORY_HEADERS}
        ${BOOT_MAIN_HEADERS}
        ${BOOT_METADATA_HEADERS}
)

# ==============================================================================
# Add binary dependencies
# ==============================================================================
target_link_libraries(${BIN_NAME}.elf
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_cmn
        arch.lib_entry
        arch.lib_types
        libraries.lib_metadata
        libraries.lib_stream
        libraries.lib_strings
        system.lib_bmt
        system.lib_elf
        system.lib_printer
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
