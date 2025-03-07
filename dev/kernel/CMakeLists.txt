# Compile each component and library
set (COMPONENTS_DIR
    # Add the path to each component here
    "clock"
    "bmt"
)

foreach (COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory(${KERNEL_DIR}/${COMPONENT_DIR})
endforeach()
