# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_PATH ${LIB_PATH})
set(LIB_NAME ${LIB_NAME})

# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(STRINGS_UTILS_DIR
    ${LIB_PATH}/code/utils
)

set(STRINGS_UTILS_SOURCES
    # Add the path to each source file here
    ${STRINGS_UTILS_DIR}/src/strings_utils_get_base_prefix.c
    ${STRINGS_UTILS_DIR}/src/strings_utils_itoa.c
    ${STRINGS_UTILS_DIR}/src/strings_utils_reverse.c
    ${STRINGS_UTILS_DIR}/src/strings_utils_utoa_raw.c
    ${STRINGS_UTILS_DIR}/src/strings_utils_utoa.c
)

set(STRINGS_UTILS_HEADERS
    ${STRINGS_UTILS_DIR}/inc
)

# ==============================================================================
# Create source and header for OPS
# ==============================================================================
set(STRINGS_OPS_DIR
    ${LIB_PATH}/code/ops
)

set(STRINGS_OPS_SOURCES
    # Add the path to each source file here
    ${STRINGS_OPS_DIR}/src/strings_ops.c
)

set(STRINGS_OPS_HEADERS
    ${STRINGS_OPS_DIR}/inc
)

# ==============================================================================
# Create library target for STRINGS
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${STRINGS_UTILS_SOURCES}
        ${STRINGS_OPS_SOURCES}
)


# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${STRINGS_UTILS_HEADERS}
        ${STRINGS_OPS_HEADERS}
    PUBLIC
        ${LIB_PATH}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PUBLIC
        # Add the path to library of other folder here
        arch.lib_types
)
