# Specify the source files
set(COMMON_SOURCES
    ${LIB_CONTAINERS_DIR}/fifo/src/containers_fifo.c
    ${LIB_CONTAINERS_DIR}/linked_chain/src/containers_linked_chain.c
)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${KERNEL_DIR}/types/include/usr
    ${LIB_CONTAINERS_DIR}/fifo/include
    ${LIB_CONTAINERS_DIR}/linked_chain/include
)

# Add library target
add_library(${LIB_CONTAINERS_NAME} STATIC ${COMMON_SOURCES})

# Link public and private header files
target_include_directories(${LIB_CONTAINERS_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS}
)
