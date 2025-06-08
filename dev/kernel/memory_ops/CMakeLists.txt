# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(MEMORY_OPS_UTILS_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

set(MEMORY_OPS_UTILS_SOURCES
    # Add the path to each source file here
    ${MEMORY_OPS_UTILS_DIR}/src/memory_ops_utils.c
)

set(MEMORY_OPS_UTILS_HEADERS
    ${MEMORY_OPS_UTILS_DIR}/include
)

# ==============================================================================
# Create library kernel target for MEMORY_OPS
# ==============================================================================
set(LIB_NAME_KRN ${MEMORY_OPS_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
    ${MEMORY_OPS_UTILS_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${MEMORY_OPS_UTILS_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${MEMORY_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Create library user target for MEMORY_OPS
# ==============================================================================
set(LIB_NAME_USR ${MEMORY_OPS_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
    ${MEMORY_OPS_UTILS_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${MEMORY_OPS_UTILS_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_usr
        ${MEMORY_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
