# ==============================================================================
# Set the architecture name
# ==============================================================================
set(ARCH_PATH ${ARCH_PATH})
set(ARCH_NAME ${ARCH_NAME})

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(FPU_INIT_DIR
    ${ARCH_PATH}/code/init
)

set(FPU_INIT_SOURCES
    # Add the path to each source file here
    ${FPU_INIT_DIR}/src/fpu_init.S
)

set(FPU_INIT_HEADERS
    ${FPU_INIT_DIR}/inc
)

# ==============================================================================
# Create library target for FPU
# ==============================================================================
add_library(${ARCH_NAME}
    STATIC
        # Add the path to each source file here
        ${FPU_INIT_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${ARCH_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${FPU_INIT_HEADERS}
    PUBLIC
        ${ARCH_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${ARCH_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
)
