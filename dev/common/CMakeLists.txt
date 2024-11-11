# Specify the source files
set(COMMON_SOURCES
    ${COMMON_DIR}/memory_alloc/src/memory_alloc.c
    ${COMMON_DIR}/memory_ops/src/memory_ops.c
    ${COMMON_DIR}/string_ops/src/string_ops.c
    ${COMMON_DIR}/string_utils/src/string_utils.c)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${COMMON_DIR}/memory_alloc/include
    ${COMMON_DIR}/memory_ops/include
    ${COMMON_DIR}/string_ops/include
    ${COMMON_DIR}/string_utils/include
    ${COMMON_DIR}/types/include)

# Add library target
add_library(${LIB_COMMON_NAME} STATIC ${COMMON_SOURCES})

# Link public and private header files
target_include_directories(${LIB_COMMON_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS}
    PRIVATE ${COMMON_DIR}/memory_alloc/src
            ${COMMON_DIR}/memory_ops/src
            ${COMMON_DIR}/string_ops/src
            ${COMMON_DIR}/string_utils/src
)
