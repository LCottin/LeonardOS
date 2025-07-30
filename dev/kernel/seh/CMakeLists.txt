# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(SEH_HANDLER_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/handler
)

set(SEH_HANDLER_SOURCES
    # Add the path to each source file here
    ${SEH_HANDLER_DIR}/src/seh_handler.c
    ${SEH_HANDLER_DIR}/src/seh_handler_fiq.S
    ${SEH_HANDLER_DIR}/src/seh_handler_irq.S
    ${SEH_HANDLER_DIR}/src/seh_handler_serr.S
    ${SEH_HANDLER_DIR}/src/seh_handler_sync.S
)

set(SEH_HANDLER_HEADERS
    ${SEH_HANDLER_DIR}/include
)

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(SEH_CTX_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/ctx
)

set(SEH_CTX_SOURCES
    # Add the path to each source file here
    ${SEH_CTX_DIR}/src/seh_ctx_init.S
    ${SEH_CTX_DIR}/src/seh_ctx_exception_table.S
)

set(SEH_CTX_HEADERS
    ${SEH_CTX_DIR}/include
)

# ==============================================================================
# Create library kernel target for SEH
# ==============================================================================
set(LIB_NAME_KRN ${SEH_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source directory here
        ${SEH_HANDLER_SOURCES}
        ${SEH_CTX_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${SEH_HANDLER_HEADERS}
        ${SEH_CTX_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
