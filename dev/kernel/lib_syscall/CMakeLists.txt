SET(LIB_SYSCALL_SOURCE
    ${LIB_SYSCALL_DIR}/src/syscall.c
)

SET(LIB_SYSCALL_HEADERS
    ${LIB_SYSCALL_DIR}/include
    ${KERNEL_DIR}/types/include/usr
)

SET(LIB_SYSCALL_PRIVATE
    ${KERNEL_DIR}/serial/include
)

# Add syscall library
add_library(${LIB_SYSCALL_NAME} STATIC ${LIB_SYSCALL_SOURCE})

# Expose only the public headers for the Syscall library
target_include_directories(${LIB_SYSCALL_NAME}
    PUBLIC ${LIB_SYSCALL_HEADERS}
    PRIVATE ${LIB_SYSCALL_PRIVATE})
