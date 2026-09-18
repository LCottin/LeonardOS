# ==============================================================================
# Set the memory name
# ==============================================================================
set(MEM_PATH ${MEM_PATH})
set(MEM_NAME ${MEM_NAME})

# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(MEMORY_OPS_UTILS_DIR
    ${MEM_PATH}/code/utils
)

set(MEMORY_OPS_UTILS_SOURCES
    # Add the path to each source file here
    ${MEMORY_OPS_UTILS_DIR}/src/memory_ops_utils_cmp.c
    ${MEMORY_OPS_UTILS_DIR}/src/memory_ops_utils_copy.c
    ${MEMORY_OPS_UTILS_DIR}/src/memory_ops_utils_set.c
)

set(MEMORY_OPS_UTILS_HEADERS
    ${MEMORY_OPS_UTILS_DIR}/inc
)

# ==============================================================================
# Create library for MEMORY_OPS
# ==============================================================================
add_library(${MEM_NAME}
    STATIC
        # Add the path to each source file here
        ${MEMORY_OPS_UTILS_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${MEM_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${MEMORY_OPS_UTILS_HEADERS}
    PUBLIC
        ${MEM_PATH}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${MEM_NAME}
    PUBLIC
        # Add the path to library of other folder here
        arch.lib_types
)
