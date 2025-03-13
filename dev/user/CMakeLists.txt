# Compile each application
set (APPLICATION_DIR
    # Add the path to each application here
    "hello_world"
)

foreach (APPLICATION_DIR ${APPLICATION_DIR})
    add_subdirectory(${USER_DIR}/${APPLICATION_DIR})
endforeach()
