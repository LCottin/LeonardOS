# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(FPU_INIT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/init
)

set(FPU_INIT_SOURCES
    # Add the path to each source file here
    ${FPU_INIT_DIR}/src/fpu_init.S
)

set(FPU_INIT_HEADERS
    ${FPU_INIT_DIR}/include
)

# ==============================================================================
# Create library kernel target for FPU
# ==============================================================================
set(LIB_NAME_KRN ${FPU_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${FPU_INIT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${FPU_INIT_HEADERS}
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
    "-Wl,--no-whole-archive"
)
