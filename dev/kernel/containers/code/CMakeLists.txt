# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for LINKED_CHAIN
# ==============================================================================
set(CONTAINERS_LINKED_CHAIN_DIR
    ${COMPONENT_NAME}/code/linked_chain
)

set(CONTAINERS_LINKED_CHAIN_SOURCES
    # Add the path to each source file here
)

set(CONTAINERS_LINKED_CHAIN_HEADERS
    ${CONTAINERS_LINKED_CHAIN_DIR}/inc
)

# ==============================================================================
# Create source and header for FIFO
# ==============================================================================
set(CONTAINERS_FIFO_DIR
    ${COMPONENT_NAME}/code/fifo
)

set(CONTAINERS_FIFO_SOURCES
    # Add the path to each source file here
    ${CONTAINERS_FIFO_DIR}/src/containers_fifo.c
)

set(CONTAINERS_FIFO_HEADERS
    ${CONTAINERS_FIFO_DIR}/inc
)

# ==============================================================================
# Create library kernel target for CONTAINERS
# ==============================================================================
set(LIB_NAME_KRN ${CONTAINERS_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${CONTAINERS_FIFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${CONTAINERS_LINKED_CHAIN_HEADERS}
        ${CONTAINERS_FIFO_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
        ${MEMORY_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Create library user target for CONTAINERS
# ==============================================================================
set(LIB_NAME_USR ${CONTAINERS_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${CONTAINERS_FIFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${CONTAINERS_LINKED_CHAIN_HEADERS}
        ${CONTAINERS_FIFO_HEADERS}
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PUBLIC "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_usr
        ${MEMORY_OPS_LIB_NAME}_usr
        ${MEMORY_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
