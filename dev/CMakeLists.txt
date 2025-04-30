# Define library names for dependencies
set(SCHEDULER_LIB_NAME    "_scheduler")
set(PCB_LIB_NAME           "_pcb")
set(LIBUSER_LIB_NAME       "_libuser")
set(TYPES_LIB_NAME         "_types")
set(ELF_LIB_NAME           "_elf")
set(SYSCALL_LIB_NAME       "_syscall")
set(BOOT_LIB_NAME          "_boot")
set(BOOT_BIN_LIB_NAME      "_boot_bin")
set(CORE_BIN_LIB_NAME      "_core_bin")
set(MEMORY_LIB_NAME        "_memory")
set(MEMORY_OPS_LIB_NAME    "_memory_ops")
set(STRINGS_LIB_NAME       "_strings")
set(CONTAINERS_LIB_NAME    "_containers")
set(UART_LIB_NAME          "_uart")
set(SERIAL_LIB_NAME        "_serial")
set(MMIO_LIB_NAME          "_mmio")
set(FPU_LIB_NAME           "_fpu")
set(CORE_LIB_NAME          "_core")
set(CLOCK_LIB_NAME         "_clock")
set(BMT_LIB_NAME           "_bmt")

# Define directories
set(KERNEL_DIR ${DEV_DIR}/kernel)
set(USER_DIR   ${DEV_DIR}/user)

# Call subdirectories cmake
add_subdirectory(${KERNEL_DIR})
add_subdirectory(${USER_DIR})
