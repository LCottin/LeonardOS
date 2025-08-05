# Compile each application
set(APPLICATION_DIR
    # Add the path to each application here
    "hello_world"
    "count_down"
)

# Set the applications directory
foreach (APPLICATION_DIR ${APPLICATION_DIR})
    add_subdirectory(${USER_DIR}/${APPLICATION_DIR})
    set_property(GLOBAL APPEND PROPERTY ALL_EXECUTABLES ${APPLICATION_DIR}.elf)
endforeach()

# Create an aggregate target that depends on all app executables
get_property(ALL_EXECUTABLES GLOBAL PROPERTY ALL_EXECUTABLES)
if(ALL_EXECUTABLES)
    add_custom_target(applications DEPENDS ${ALL_EXECUTABLES})
endif()
