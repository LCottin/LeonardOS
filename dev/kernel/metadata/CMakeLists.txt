# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create library user target for METADATA
# ==============================================================================
set(LIB_NAME_USR ${METADATA_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    INTERFACE
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    INTERFACE
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)
