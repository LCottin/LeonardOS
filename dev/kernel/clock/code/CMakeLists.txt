# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(CLOCK_INFO_DIR
    ${COMPONENT_NAME}/code/info
)

set(CLOCK_INFO_SOURCES
    # Add the path to each source file here
    ${CLOCK_INFO_DIR}/src/clock_info_get_cycle_count.S
    ${CLOCK_INFO_DIR}/src/clock_info_get_frequency.S
    ${CLOCK_INFO_DIR}/src/clock_info_get_time.c
)

set(CLOCK_INFO_HEADERS
    ${CLOCK_INFO_DIR}/inc
)

# ==============================================================================
# Create library kernel target for CLOCK
# ==============================================================================
set(LIB_NAME_KRN ${CLOCK_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${CLOCK_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${CLOCK_INFO_HEADERS}
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
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Create library user target for CLOCK
# ==============================================================================
set(LIB_NAME_USR ${CLOCK_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${CLOCK_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${CLOCK_CTX_HEADERS}
        ${CLOCK_INFO_HEADERS}
        ${CLOCK_INIT_HEADERS}
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
