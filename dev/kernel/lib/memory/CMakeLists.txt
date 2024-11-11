# Specify the source files
set(COMMON_SOURCES
    ${LIB_MEMORY_DIR}/memory_alloc/src/memory_alloc.c
    ${LIB_MEMORY_DIR}/memory_ops/src/memory_ops.c)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${LIB_MEMORY_DIR}/memory_alloc/include
    ${LIB_MEMORY_DIR}/memory_ops/include
    ${LIB_DIR}/types/include)

# Add library target
add_library(${LIB_MEMORY_NAME} STATIC ${COMMON_SOURCES})

# Link public and private header files
target_include_directories(${LIB_MEMORY_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS}
    PRIVATE ${COMMON_DIR}/memory_alloc/src
            ${COMMON_DIR}/memory_ops/src
)
