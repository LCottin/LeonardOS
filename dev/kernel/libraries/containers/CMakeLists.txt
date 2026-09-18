# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_PATH ${LIB_PATH})
set(LIB_NAME ${LIB_NAME})

# ==============================================================================
# Create source and header for RING_BUFFER
# ==============================================================================
set(CONTAINERS_RING_BUFFER_DIR
    ${LIB_PATH}/code/ring_buffer
)

set(CONTAINERS_RING_BUFFER_SOURCES
    # Add the path to each source file here
    ${CONTAINERS_RING_BUFFER_DIR}/src/containers_ring_buffer_init.c
    ${CONTAINERS_RING_BUFFER_DIR}/src/containers_ring_buffer_is_empty.c
    ${CONTAINERS_RING_BUFFER_DIR}/src/containers_ring_buffer_pop.c
    ${CONTAINERS_RING_BUFFER_DIR}/src/containers_ring_buffer_push.c
)

set(CONTAINERS_RING_BUFFER_HEADERS
    ${CONTAINERS_RING_BUFFER_DIR}/inc
)

# ==============================================================================
# Create library target for CONTAINERS
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${CONTAINERS_RING_BUFFER_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${CONTAINERS_RING_BUFFER_HEADERS}
    PUBLIC
        ${LIB_PATH}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PUBLIC
        # Add the path to library of other folder here
        arch.lib_types
        memory.lib_tools
)
