# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create library kernel target for COMPONENT
# ==============================================================================
set(LIB_NAME_KRN ${COMPONENT_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source directory here
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
# ==============================================================================
# Create library user target for COMPONENT
# ==============================================================================
set(LIB_NAME_USR ${COMPONENT_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source directory here
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other private folder here
    PUBLIC
        # Add the path to library of other public folder here
        ${TYPES_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
