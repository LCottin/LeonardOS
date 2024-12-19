set(BOOT_NAME "boot")
set(BOOT_DIR ${KERNEL_DIR}/${BOOT_NAME})
set(BOOT_BIN_DIR ${BOOT_DIR}_bin)

set(CORE_NAME "core")
set(CORE_DIR ${KERNEL_DIR}/${CORE_NAME})
set(CORE_BIN_DIR ${CORE_DIR}_bin)

set(LIB_MEMORY_NAME  "Memory")
set(LIB_MEMORY_DIR ${KERNEL_DIR}/lib_memory)

set(LIB_STRING_NAME  "String")
set(LIB_STRING_DIR ${KERNEL_DIR}/lib_string)

set(LIB_SYSCALL_NAME "Sycall")
set(LIB_SYSCALL_DIR ${KERNEL_DIR}/lib_syscall)

set(LIB_CONTAINERS_NAME "Containers")
set(LIB_CONTAINERS_DIR ${KERNEL_DIR}/lib_containers)

set(LIB_USER_NAME "User")
set(LIB_USER_DIR ${KERNEL_DIR}/lib_user)

# Call subdirectories cmake
add_subdirectory(${BOOT_BIN_DIR})
add_subdirectory(${CORE_BIN_DIR})
add_subdirectory(${LIB_MEMORY_DIR})
add_subdirectory(${LIB_STRING_DIR})
add_subdirectory(${LIB_SYSCALL_DIR})
add_subdirectory(${LIB_CONTAINERS_DIR})
add_subdirectory(${LIB_USER_DIR})
