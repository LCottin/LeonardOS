# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(CLOCK_CTX_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/ctx
)

set(CLOCK_CTX_SOURCES
    # Add the path to each source file here
    ${CLOCK_CTX_DIR}/src/clock_data.c
)

set (CLOCK_CTX_HEADERS
    ${CLOCK_CTX_DIR}/include
)

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(CLOCK_INFO_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/info
)

set(CLOCK_INFO_SOURCES
    # Add the path to each source file here
    ${CLOCK_INFO_DIR}/src/clock_info_get_cycle_count.s
    ${CLOCK_INFO_DIR}/src/clock_info_get_frequency.s
    ${CLOCK_INFO_DIR}/src/clock_info_get_time.c
)

set (CLOCK_INFO_HEADERS
    ${CLOCK_INFO_DIR}/include
)

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(CLOCK_INIT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/init
)

set(CLOCK_INIT_SOURCES
    # Add the path to each source file here
    ${CLOCK_INIT_DIR}/src/clock_init.c
)

set (CLOCK_INIT_HEADERS
    ${CLOCK_INIT_DIR}/include
)

# ==============================================================================
# Create library target for CLOCK
# ==============================================================================
set (LIB_NAME ${CLOCK_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${CLOCK_CTX_SOURCES}
        ${CLOCK_INFO_SOURCES}
        ${CLOCK_INIT_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${CLOCK_CTX_HEADERS}
        ${CLOCK_INFO_HEADERS}
        ${CLOCK_INIT_HEADERS}
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
