# Specify the source files
set(COMMON_SOURCES
    ${LIB_STRING_DIR}/ops/src/string_ops.c
    ${LIB_STRING_DIR}/utils/src/string_utils.c
)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${KERNEL_DIR}/types/include/usr
    ${LIB_STRING_DIR}/ops/include
    ${LIB_STRING_DIR}/utils/include
)

# Add library target
add_library(${LIB_STRING_NAME} STATIC ${COMMON_SOURCES})

# Link public and private header files
target_include_directories(${LIB_STRING_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS}
    PRIVATE ${LIB_STRING_DIR}/ops/src
            ${LIB_STRING_DIR}/utils/src
)
