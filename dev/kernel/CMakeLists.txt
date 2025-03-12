# Compile each component and library
set (COMPONENTS_DIR
    # Add the path to each component here
    "elf"
    "libuser"
    "syscall"
    "boot"
    "boot_bin"
    "core_bin"
    "memory"
    "memory_ops"
    "strings"
    "containers"
    "types"
    "uart"
    "serial"
    "mmio"
    "fpu"
    "core"
    "clock"
    "bmt"
)

# Define library names for dependencies
set (ELF_LIB_NAME           "_elf")
set (LIBUSER_LIB_NAME       "_libuser")
set (SYSCALL_LIB_NAME       "_syscall")
set (BOOT_LIB_NAME          "_boot")
set (BOOT_BIN_LIB_NAME      "_boot_bin")
set (CORE_BIN_LIB_NAME      "_core_bin")
set (MEMORY_LIB_NAME        "_memory")
set (MEMORY_OPS_LIB_NAME    "_memory_ops")
set (STRINGS_LIB_NAME       "_strings")
set (CONTAINERS_LIB_NAME    "_containers")
set (TYPES_LIB_NAME         "_types")
set (UART_LIB_NAME          "_uart")
set (SERIAL_LIB_NAME        "_serial")
set (MMIO_LIB_NAME          "_mmio")
set (FPU_LIB_NAME           "_fpu")
set (CORE_LIB_NAME          "_core")
set (CLOCK_LIB_NAME         "_clock")
set (BMT_LIB_NAME           "_bmt")

foreach (COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory(${KERNEL_DIR}/${COMPONENT_DIR})
endforeach()
