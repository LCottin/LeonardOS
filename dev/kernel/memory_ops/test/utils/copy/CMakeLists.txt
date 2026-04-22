# ==============================================================================
# Set the output directory of the library
# ==============================================================================
set(BIN_PATH ${ARG1})
set(BIN_NAME ${ARG2})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_TEST_DIR}/${BIN_NAME})

# ==============================================================================
# Create executable target
# ==============================================================================
add_executable(${BIN_NAME}.elf ${BIN_PATH}/memory_ops_utils_copy.c)

# ==============================================================================
# Link with the component libraries
# ==============================================================================
target_link_libraries(${BIN_NAME}.elf
    PRIVATE "-Wl,--whole-archive"
        # Add component libraries here
        ${TYPES_LIB_NAME}_krn
        ${SPEC_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Set custom linker options, including the generation of the .map file
# ==============================================================================
target_link_options(${BIN_NAME}.elf
    PRIVATE
        "-T${TEST_LINKER_SCRIPT}"
        "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.map"
)

# ==============================================================================
# Generate .bin, .elf.stripped and .map files
# ==============================================================================
add_custom_command(
    TARGET
    ${BIN_NAME}.elf
    POST_BUILD

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${BIN_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.elf.stripped

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${BIN_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.bin
)
