# Specify the source files
set(COMMON_SOURCES
    ${LIB_CONTAINERS_DIR}/fifo/src/containers_fifo.c
    ${LIB_CONTAINERS_DIR}/linked_chain/src/containers_linked_chain.c)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${LIB_CONTAINERS_DIR}/fifo/include
    ${LIB_CONTAINERS_DIR}/linked_chain/include
    ${LIB_DIR}/types/include)

# Add library target
add_library(${LIB_CONTAINERS_NAME} STATIC ${COMMON_SOURCES})

# Link libmemory
target_link_libraries(${LIB_CONTAINERS_NAME} ${LIB_MEMORY_NAME})

# Link public and private header files
target_include_directories(${LIB_CONTAINERS_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS})

 # Ensure that the lib container is built after lib memory
 add_dependencies(${LIB_CONTAINERS_NAME} ${LIB_MEMORY_NAME})
