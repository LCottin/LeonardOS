# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for ASSERT
# ==============================================================================
set(SPEC_ASSERT_DIR
    ${COMPONENT_NAME}/code/assert
)

set(SPEC_ASSERT_SOURCES
    # Add the path to each source file here
    ${SPEC_ASSERT_DIR}/src/spec_assert_data.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_get_count.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_get_failure.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_get_passed.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_char.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_mem.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_ptr.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_u8.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_u16.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_u32.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal_u64.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record_equal.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_record.c
    ${SPEC_ASSERT_DIR}/src/spec_assert_reset.c
)

set(SPEC_ASSERT_HEADERS
    ${SPEC_ASSERT_DIR}/inc
)


# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(SPEC_UTILS_DIR
    ${COMPONENT_NAME}/code/utils
)

set(SPEC_UTILS_SOURCES
    # Add the path to each source file here
    ${SPEC_UTILS_DIR}/src/spec_utils_memcmp.c
    ${SPEC_UTILS_DIR}/src/spec_utils_memcpy.c
    ${SPEC_UTILS_DIR}/src/spec_utils_memset.c
    ${SPEC_UTILS_DIR}/src/spec_utils_print_string.c
    ${SPEC_UTILS_DIR}/src/spec_utils_print_uint.c
)

set(SPEC_UTILS_HEADERS
    ${SPEC_UTILS_DIR}/inc
)

# ==============================================================================
# Create source and header for RUN
# ==============================================================================
set(SPEC_RUN_DIR
    ${COMPONENT_NAME}/code/run
)

set(SPEC_RUN_SOURCES
    # Add the path to each source file here
    ${SPEC_RUN_DIR}/src/spec_run_entry.S
    ${SPEC_RUN_DIR}/src/spec_run_suite.c
)

set(SPEC_RUN_HEADERS
    ${SPEC_RUN_DIR}/inc
)

# ==============================================================================
# Create library kernel target for SPEC
# ==============================================================================
set(LIB_NAME_KRN ${SPEC_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${SPEC_ASSERT_SOURCES}
        ${SPEC_UTILS_SOURCES}
        ${SPEC_RUN_SOURCES}
)
# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${SPEC_ASSERT_HEADERS}
        ${SPEC_RUN_HEADERS}
        ${SPEC_UTILS_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
