# Compile each component
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
    "uart"
    "mmio"
    "fpu"
    "core"
    "clock"
    "bmt"
)

# Compile each library
set(LIBRARIES_DIR
    # Add the path to each library here
    "types"
)

set (BINARY_DIR
    "boot_bin"
    "core_bin"
)

# Set the library component directory
foreach (LIBRARY_DIR ${LIBRARIES_DIR})
    add_subdirectory_custom(${KERNEL_DIR}/${LIBRARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR})
endforeach()

# Set the code component directory
foreach (COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory_custom(${KERNEL_DIR}/${COMPONENT_DIR}/code ${CMAKE_CURRENT_SOURCE_DIR}/${COMPONENT_DIR})
endforeach()

# Set the binaries directory
foreach (BINARY_DIR ${BINARY_DIR})
    add_subdirectory(${KERNEL_DIR}/${BINARY_DIR})
endforeach()

#TODO: Add test components
# Set the test component directory
# foreach (COMPONENT_DIR ${COMPONENTS_DIR})
#     add_subdirectory(${KERNEL_DIR}/${COMPONENT_DIR}/test)
    # set_property(GLOBAL APPEND PROPERTY ALL_APPLICATIONS ${APPLICATION_DIR}.elf)
# endforeach()

# Create an aggregate target that depends on all tests
# get_property(ALL_TESTS GLOBAL PROPERTY ALL_TESTS)
# if(ALL_TESTS)
#     add_custom_target(tests DEPENDS ${ALL_TESTS})
# endif()
