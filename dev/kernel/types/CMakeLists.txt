# ==============================================================================
# Create library kernel target for TYPES
# ==============================================================================
set(LIB_NAME_KRN ${TYPES_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    INTERFACE
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Create library user target for TYPES
# ==============================================================================
set(LIB_NAME_USR ${TYPES_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    INTERFACE
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)
