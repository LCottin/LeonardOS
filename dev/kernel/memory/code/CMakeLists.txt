# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for STREAM
# ==============================================================================
set(MEMORY_STREAM_DIR
    ${COMPONENT_NAME}/code/stream
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
    ${COMPONENT_NAME}/code/alloc
)

set(MEMORY_ALLOC_SOURCES
    # Add the path to each source file here
    ${MEMORY_ALLOC_DIR}/src/memory_alloc.c
)

set(MEMORY_ALLOC_HEADERS
    ${MEMORY_ALLOC_DIR}/inc
)

# ==============================================================================
# Create library kernel target for MEMORY
# ==============================================================================
set(LIB_NAME_KRN ${MEMORY_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${MEMORY_STREAM_SOURCES}
        ${MEMORY_ALLOC_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${MEMORY_STREAM_HEADERS}
        ${MEMORY_ALLOC_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
        ${STREAM_LIB_NAME}_krn
)

# ==============================================================================
# Create library user target for MEMORY
# ==============================================================================
set(LIB_NAME_USR ${MEMORY_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${MEMORY_STREAM_SOURCES}
        ${MEMORY_ALLOC_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${MEMORY_STREAM_HEADERS}
        ${MEMORY_ALLOC_HEADERS}
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE
        # Add the path to library of other folder here
        ${STREAM_LIB_NAME}_krn
    PUBLIC
        ${TYPES_LIB_NAME}_usr
        ${MEMORY_OPS_LIB_NAME}_usr
)
