# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create library kernel target for TYPES
# ==============================================================================
set(LIB_NAME_KRN ${STREAM_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    INTERFACE
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    INTERFACE
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)
