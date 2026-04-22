# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(STRINGS_UTILS_DIR
    ${COMPONENT_NAME}/code/utils
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
    ${COMPONENT_NAME}/code/ops
)

set(STRINGS_OPS_SOURCES
    # Add the path to each source file here
    ${STRINGS_OPS_DIR}/src/strings_ops.c
)

set(STRINGS_OPS_HEADERS
    ${STRINGS_OPS_DIR}/inc
)

# ==============================================================================
# Create library kernel target for STRINGS
# ==============================================================================
set(LIB_NAME_KRN ${STRINGS_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${STRINGS_UTILS_SOURCES}
        ${STRINGS_SOURCES_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${STRINGS_UTILS_HEADERS}
        ${STRINGS_OPS_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Create library user target for STRINGS
# ==============================================================================
set(LIB_NAME_USR ${STRINGS_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${STRINGS_UTILS_SOURCES}
        ${STRINGS_SOURCES_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${STRINGS_UTILS_HEADERS}
        ${STRINGS_OPS_HEADERS}
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PUBLIC "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_usr
        ${PRINTER_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
