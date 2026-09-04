# Build kernel space
set(KERNEL_DIR ${DEV_DIR}/kernel)
add_subdirectory(${KERNEL_DIR})

# Build user space
set(USER_DIR   ${DEV_DIR}/user)
add_subdirectory(${USER_DIR})
