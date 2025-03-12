# ==============================================================================
# Create library target for TYPES
# ==============================================================================
set (LIB_NAME ${TYPES_LIB_NAME})
add_library(${LIB_NAME}
    INTERFACE
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)
