# Compile each application
set(APPLICATION_DIR
    # Add the path to each application here
    "hello_world"
    "count_down"
)

set(USER_LINKER_SECTIONS_SCRIPT_PATH "${USER_DIR}/linker_sections.ld")

# Set the applications directory
foreach (APPLICATION_DIR ${APPLICATION_DIR})
    add_subdirectory(${USER_DIR}/${APPLICATION_DIR})
    set_property(GLOBAL APPEND PROPERTY ALL_APPLICATIONS ${APPLICATION_DIR}.elf)
endforeach()

# Create an aggregate target that depends on all app executables
get_property(ALL_APPLICATIONS GLOBAL PROPERTY ALL_APPLICATIONS)
if(ALL_APPLICATIONS)
    add_custom_target(applications DEPENDS ${ALL_APPLICATIONS})
endif()
