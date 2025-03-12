# Compile each component and library
set (COMPONENTS_DIR
    # Add the path to each component here
)

foreach (COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory(${COMPONENT_DIR})
endforeach()
