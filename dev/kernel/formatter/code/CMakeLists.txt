# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for PARSE
# ==============================================================================
set(FORMATTER_PARSE_DIR
    ${COMPONENT_NAME}/code/parse
)

set(FORMATTER_PARSE_SOURCES
    # Add the path to each source file here
    ${FORMATTER_PARSE_DIR}/src/formatter_parse.c
)

set(FORMATTER_PARSE_HEADERS
    ${FORMATTER_PARSE_DIR}/inc
)

# ==============================================================================
# Create library kernel target for FORMATTER
# ==============================================================================
set(LIB_NAME_KRN ${FORMATTER_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${FORMATTER_PARSE_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${FORMATTER_PARSE_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
        ${STREAM_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)


# ==============================================================================
# Create library kernel target for FORMATTER
# ==============================================================================
set(LIB_NAME_USR ${FORMATTER_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${FORMATTER_PARSE_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${FORMATTER_PARSE_HEADERS}
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${STREAM_LIB_NAME}_krn
    PUBLIC
        ${TYPES_LIB_NAME}_usr
        ${STRINGS_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
