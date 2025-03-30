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

set(CORE_MAIN_HEADERS
    ${CORE_MAIN_DIR}/include
)

# ==============================================================================
# Create library kernel target for CORE
# ==============================================================================
set(LIB_NAME_KRN ${CORE_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${CORE_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${CORE_MAIN_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${SERIAL_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
        ${MEMORY_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
        ${FPU_LIB_NAME}_krn
        ${CLOCK_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
