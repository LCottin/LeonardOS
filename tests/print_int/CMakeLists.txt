# ==============================================================================
# Set the output directory of the executable
# ==============================================================================
set(TEST_NAME "print_int")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_TESTS_DIR}/${TEST_NAME})

# ==============================================================================
# Linker script file path
# ==============================================================================
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/../linker.ld)

# ==============================================================================
# Create source and header for PART
# ==============================================================================
set(TEST_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(TEST_SOURCES
    ${TEST_DIR}/entry/test_entry.c
    # Add other sources here
    ${TEST_DIR}/cases/print_int_negative.c
    ${TEST_DIR}/cases/print_int_positive.c
)

set(TEST_HEADERS
    ${TEST_DIR}/include/print_int.h
)

# ==============================================================================
# Create executable target
# ==============================================================================
add_executable(${TEST_NAME}.elf ${TEST_SOURCES})

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${TEST_NAME}.elf
    PRIVATE
        # Add the path to each header directory here
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${TEST_NAME}.elf
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_usr
        ${LIBUSER_LIB_NAME}_usr
        ${TEST_LIB_NAME}
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Set custom linker options, including the generation of the .map file
# ==============================================================================
target_link_options(${TEST_NAME}.elf
    PRIVATE
        "-T${LINKER_SCRIPT}"
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
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TEST_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}.bin
)

