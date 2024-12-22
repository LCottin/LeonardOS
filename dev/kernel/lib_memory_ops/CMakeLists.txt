# Specify the source files
set(COMMON_SOURCES
    ${LIB_MEMORY_DIR}/src/memory_ops.c
)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${KERNEL_DIR}/types/include
    ${LIB_MEMORY_DIR}/include
)

# Add library target
add_library(${LIB_MEMORY_NAME} STATIC ${COMMON_SOURCES})

# Link public and private header files
target_include_directories(${LIB_MEMORY_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS}
    PRIVATE ${LIB_MEMORY_DIR}/src
)
