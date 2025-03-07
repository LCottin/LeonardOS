# ==============================================================================
# Create library target for component
# ==============================================================================
set (LIB_NAME "component_lib")
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${KERNEL_DIR}/types/include
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE -Wl, --whole-archive
        # Add the path to library of other folder here
)
