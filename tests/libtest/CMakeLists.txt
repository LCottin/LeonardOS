# ==============================================================================
# Create library kernel target for LIBTEST
# ==============================================================================
set(LIB_NAME ${TEST_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
    # Add the path to each source directory here
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libtest_print_str.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libtest_memcpy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libtest_finish.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libtest_run.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libtest_start.c
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE "-Wl,--whole-archive"
        # Link to lib type only as the framework shall be independent
        ${TYPES_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
