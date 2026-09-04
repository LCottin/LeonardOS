# ==============================================================================
# Set the memory name
# ==============================================================================
set(MEM_PATH ${MEM_PATH})
set(MEM_NAME ${MEM_NAME})

# ==============================================================================
# Create source and header for STREAM
# ==============================================================================
set(MEMORY_STREAM_DIR
    ${MEM_PATH}/code/stream
)

set(MEMORY_STREAM_SOURCES
    # Add the path to each source file here
    ${MEMORY_STREAM_DIR}/src/memory_stream_data.c
    ${MEMORY_STREAM_DIR}/src/memory_stream_get.c
    ${MEMORY_STREAM_DIR}/src/memory_stream_reset.c
    ${MEMORY_STREAM_DIR}/src/memory_stream_write_byte.c
)

set(MEMORY_STREAM_HEADERS
    ${MEMORY_STREAM_DIR}/inc
)

# ==============================================================================
# Create source and header for ALLOC
# ==============================================================================
set(MEMORY_ALLOC_DIR
    ${MEM_PATH}/code/alloc
)

set(MEMORY_ALLOC_SOURCES
    # Add the path to each source file here
    ${MEMORY_ALLOC_DIR}/src/memory_alloc.c
)

set(MEMORY_ALLOC_HEADERS
    ${MEMORY_ALLOC_DIR}/inc
)

# ==============================================================================
# Create library target for MEMORY
# ==============================================================================
add_library(${MEM_NAME}
    STATIC
        # Add the path to each source file here
        ${MEMORY_STREAM_SOURCES}
        ${MEMORY_ALLOC_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${MEM_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${MEMORY_STREAM_HEADERS}
        ${MEMORY_ALLOC_HEADERS}
    PUBLIC
        ${MEM_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${MEM_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        memory.lib_tools
        libraries.lib_stream
)
