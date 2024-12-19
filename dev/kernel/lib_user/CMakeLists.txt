# Specify the source files
set(COMMON_SOURCES
    ${LIB_USER_DIR}/src/libuser.c
)

# Add public header directory
set(COMMON_PUBLIC_HEADERS
    ${LIB_USER_DIR}/include/
    ${KERNEL_DIR}/types/include/
)

# Add library target
add_library(${LIB_USER_NAME} STATIC ${COMMON_SOURCES})

# Link libsyscall
target_link_libraries(${LIB_USER_NAME} ${LIB_SYSCALL_NAME})

# Ensure that the lib user is built after lib syscall
add_dependencies(${LIB_USER_NAME} ${LIB_SYSCALL_NAME})

# Link public and private header files
target_include_directories(${LIB_USER_NAME}
    PUBLIC ${COMMON_PUBLIC_HEADERS})

