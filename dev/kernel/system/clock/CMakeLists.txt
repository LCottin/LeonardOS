# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(CLOCK_INFO_DIR
    ${SYS_PATH}/code/info
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
# Create library target for CLOCK
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source file here
        ${CLOCK_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${CLOCK_INFO_HEADERS}
    PUBLIC
        ${SYS_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${SYS_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
)
