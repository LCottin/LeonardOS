# Compile each component and library
set(COMPONENTS_DIR
    # Add the path to each component here
    "seh"
    "printer"
    "scheduler"
    "pcb"
    "elf"
    "libuser"
    "syscall"
    "boot"
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

set (BINARY_DIR
    "boot_bin"
    "core_bin"
)

# Set the libraries directory
foreach (COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory(${KERNEL_DIR}/${COMPONENT_DIR})
endforeach()

# Set the binaries directory
foreach (BINARY_DIR ${BINARY_DIR})
    add_subdirectory(${KERNEL_DIR}/${BINARY_DIR})
endforeach()
