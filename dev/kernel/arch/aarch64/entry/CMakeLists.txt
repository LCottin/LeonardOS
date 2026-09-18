# ==============================================================================
# Set the architecture name
# ==============================================================================
set(ARCH_PATH ${ARCH_PATH})
set(ARCH_NAME ${ARCH_NAME})

# ==============================================================================
# Create source and header for ENTRY
# ==============================================================================
set(ARCH_ENTRY_DIR
    ${ARCH_PATH}/code/entry
)

set(ARCH_ENTRY_SOURCES
    # Add the path to each source file here
    ${ARCH_ENTRY_DIR}/src/arch_entry_launch_kernel.S
    ${ARCH_ENTRY_DIR}/src/arch_entry.S
)

set(ARCH_ENTRY_HEADERS
    ${ARCH_ENTRY_DIR}/inc
)

# ==============================================================================
# Create library target for ENTRY
# ==============================================================================
add_library(${ARCH_NAME}
    STATIC
        # Add the path to each source directory here
        ${ARCH_ENTRY_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${ARCH_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${ARCH_ENTRY_HEADERS}
    PUBLIC
        ${ARCHITECTURE_CMN_PATH}/inc/krn  # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${ARCH_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
)
