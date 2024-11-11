# Specify the source files
set(COMMON_SOURCES
    ${LIB_STRING_DIR}/string_ops/src/string_ops.c
    ${LIB_STRING_DIR}/string_utils/src/string_utils.c)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${LIB_STRING_DIR}/string_ops/include
    ${LIB_STRING_DIR}/string_utils/include
    ${LIB_DIR}/types/include)

# Add library target
add_library(${LIB_STRING_NAME} STATIC ${COMMON_SOURCES})

# Link public and private header files
target_include_directories(${LIB_STRING_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS}
    PRIVATE ${COMMON_DIR}/string_ops/src
            ${COMMON_DIR}/string_utils/src
)
