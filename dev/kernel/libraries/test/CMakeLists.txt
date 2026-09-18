# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_PATH ${LIB_PATH})
set(LIB_NAME ${LIB_NAME})

# ==============================================================================
# Create source and header for ASSERT
# ==============================================================================
set(TEST_ASSERT_DIR
    ${LIB_PATH}/code/assert
)

set(TEST_ASSERT_SOURCES
    # Add the path to each source file here
    ${TEST_ASSERT_DIR}/src/spec_assert_data.c
    ${TEST_ASSERT_DIR}/src/spec_assert_get_count.c
    ${TEST_ASSERT_DIR}/src/spec_assert_get_failure.c
    ${TEST_ASSERT_DIR}/src/spec_assert_get_passed.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_char.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_mem.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_ptr.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_u8.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_u16.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_u32.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal_u64.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record_equal.c
    ${TEST_ASSERT_DIR}/src/spec_assert_record.c
    ${TEST_ASSERT_DIR}/src/spec_assert_reset.c
)

set(TEST_ASSERT_HEADERS
    ${TEST_ASSERT_DIR}/inc
)


# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(TEST_UTILS_DIR
    ${LIB_PATH}/code/utils
)

set(TEST_UTILS_SOURCES
    # Add the path to each source file here
    ${TEST_UTILS_DIR}/src/spec_utils_memcmp.c
    ${TEST_UTILS_DIR}/src/spec_utils_memcpy.c
    ${TEST_UTILS_DIR}/src/spec_utils_memset.c
    ${TEST_UTILS_DIR}/src/spec_utils_print_string.c
    ${TEST_UTILS_DIR}/src/spec_utils_print_uint.c
)

set(TEST_UTILS_HEADERS
    ${TEST_UTILS_DIR}/inc
)

# ==============================================================================
# Create source and header for RUN
# ==============================================================================
set(TEST_RUN_DIR
    ${LIB_PATH}/code/run
)

set(TEST_RUN_SOURCES
    # Add the path to each source file here
    ${TEST_RUN_DIR}/src/spec_run_entry.S
    ${TEST_RUN_DIR}/src/spec_run_suite.c
)

set(TEST_RUN_HEADERS
    ${TEST_RUN_DIR}/inc
)

# ==============================================================================
# Create library target for TEST
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${TEST_ASSERT_SOURCES}
        ${TEST_UTILS_SOURCES}
        ${TEST_RUN_SOURCES}
)
# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${TEST_ASSERT_HEADERS}
        ${TEST_RUN_HEADERS}
        ${TEST_UTILS_HEADERS}
    PUBLIC
        ${LIB_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
)
