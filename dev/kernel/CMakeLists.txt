# Compile each component and library
set(COMPONENTS_DIR
    # Add the path to each component here
    "printer"
    "scheduler"
    "pcb"
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
    "mmio"
    "fpu"
    "core"
    "clock"
    "bmt"
)

foreach (COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory(${KERNEL_DIR}/${COMPONENT_DIR})
endforeach()
