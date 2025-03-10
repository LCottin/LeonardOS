# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(STRINGS_UTILS_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

set(STRINGS_UTILS_SOURCES
    # Add the path to each source file here
    ${STRINGS_UTILS_DIR}/src/strings_utils.c
)

set (STRINGS_UTILS_HEADERS
    ${STRINGS_UTILS_DIR}/include
)

# ==============================================================================
# Create source and header for OPS
# ==============================================================================
set(STRINGS_OPS_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/ops
)

set(STRINGS_OPS_SOURCES
    # Add the path to each source file here
    ${STRINGS_OPS_DIR}/src/strings_ops.c
)

set (STRINGS_OPS_HEADERS
    ${STRINGS_OPS_DIR}/include
)

# ==============================================================================
# Create library target for STRINGS
# ==============================================================================
set (LIB_NAME ${STRINGS_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${STRINGS_UTILS_SOURCES}
        ${STRINGS_SOURCES_SOURCES}
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
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}
    "-Wl,--no-whole-archive"
)
