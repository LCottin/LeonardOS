# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(CORE_MAIN_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/main
)

set(CORE_MAIN_SOURCES
    # Add the path to each source file here
    ${CORE_MAIN_DIR}/src/core_main.c
)

set (CORE_MAIN_HEADERS
    ${CORE_MAIN_DIR}/include
)

# ==============================================================================
# Create library target for CORE
# ==============================================================================
set (LIB_NAME ${CORE_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${CORE_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${CORE_MAIN_HEADERS}
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
        ${SERIAL_LIB_NAME}
        ${STRINGS_LIB_NAME}
        ${MEMORY_LIB_NAME}
        ${MEMORY_OPS_LIB_NAME}
        ${FPU_LIB_NAME}
        ${CLOCK_LIB_NAME}
    "-Wl,--no-whole-archive"
)
