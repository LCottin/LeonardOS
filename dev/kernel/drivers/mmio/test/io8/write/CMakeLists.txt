# ==============================================================================
# Set the output directory of the library
# ==============================================================================
set(SRC_PATH ${SRC_PATH})
set(TEST_NAME ${TEST_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_TEST_DIR}/${BIN_NAME})

# ==============================================================================
# Create executable target
# ==============================================================================
add_executable(${TEST_NAME}.elf
    ${DRIVERS_PATH}/mmio/code/io8/src/mmio_io8_write.c
    ${SRC_PATH}/mmio_io8_write.c
    ${SRC_PATH}/mmio_io8_write_tc.c)

# ==============================================================================
# Add include directories needed by the real source file under test
# ==============================================================================
target_include_directories(${TEST_NAME}.elf
    PRIVATE
        ${DRIVERS_PATH}/mmio/inc/krn
)

# ==============================================================================
# Link with the component libraries
# ==============================================================================
target_link_libraries(${TEST_NAME}.elf
    PRIVATE
        # Add component libraries here
        arch.lib_types
        libraries.lib_test
)

# ==============================================================================
# Set custom linker options, including the generation of the .map file
# ==============================================================================
target_link_options(${TEST_NAME}.elf
    PRIVATE
        "-T${TEST_LINKER_SCRIPT}"
        "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}.map"
)

# ==============================================================================
# Generate .bin, .elf.stripped and .map files
# ==============================================================================
add_custom_command(
    TARGET
    ${TEST_NAME}.elf
    POST_BUILD

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${TEST_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}.elf.stripped

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TEST_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.bin
)
