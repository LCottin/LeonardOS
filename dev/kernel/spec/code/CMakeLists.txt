# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

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
        ${SPEC_UTILS_SOURCES}
        ${SPEC_RUN_SOURCES}
)
# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
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
