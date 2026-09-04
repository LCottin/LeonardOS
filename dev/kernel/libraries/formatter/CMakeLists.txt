# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_PATH ${LIB_PATH})
set(LIB_NAME ${LIB_NAME})

# ==============================================================================
# Create source and header for PARSE
# ==============================================================================
set(FORMATTER_PARSE_DIR
    ${LIB_PATH}/code/parse
)

set(FORMATTER_PARSE_SOURCES
    # Add the path to each source file here
    ${FORMATTER_PARSE_DIR}/src/formatter_parse.c
)

set(FORMATTER_PARSE_HEADERS
    ${FORMATTER_PARSE_DIR}/inc
)

# ==============================================================================
# Create library target for FORMATTER
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${FORMATTER_PARSE_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${FORMATTER_PARSE_HEADERS}
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
        libraries.lib_strings
        libraries.lib_stream
)
