# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(MMU_INIT_DIR
    ${COMPONENT_NAME}/code/init
)

set(MMU_INIT_SOURCES
    # Add the path to each source file here
)

set(MMU_INIT_HEADERS
    ${MMU_INIT_DIR}/inc
)

# ==============================================================================
# Create library kernel target for MMU
# ==============================================================================
set(LIB_NAME_KRN ${MMU_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${MMU_INIT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${MMU_INIT_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
