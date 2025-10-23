# Define each test
set(TEST_DIR
    # Add the path to each test here
    print_int
)

# Define libtest
set (TEST_LIB_NAME "_test")
add_subdirectory(libtest)

# Set the test directory
foreach (TEST_DIR ${TEST_DIR})
    add_subdirectory(${TEST_DIR})
    set_property(GLOBAL APPEND PROPERTY ALL_TESTS ${TEST_DIR}.elf)
endforeach()

# Create an aggregate target that depends on all app executables
get_property(ALL_TESTS GLOBAL PROPERTY ALL_TESTS)
if(ALL_TESTS)
    add_custom_target(tests DEPENDS ${ALL_TESTS})
endif()
