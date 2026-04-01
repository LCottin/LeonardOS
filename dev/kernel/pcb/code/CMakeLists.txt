# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(PCB_INIT_DIR
    ${COMPONENT_NAME}/code/init
)

set(PCB_INIT_SOURCES
    # Add the path to each source file here
    ${PCB_INIT_DIR}/src/pcb_init.c
)

set(PCB_INIT_HEADERS
    ${PCB_INIT_DIR}/inc
)

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(PCB_CTX_DIR
    ${COMPONENT_NAME}/code/ctx
)

set(PCB_CTX_SOURCES
    # Add the path to each source file here
    ${PCB_CTX_DIR}/src/pcb_ctx_data.c
    ${PCB_CTX_DIR}/src/pcb_ctx_get_count.c
    ${PCB_CTX_DIR}/src/pcb_ctx_get_app_entry.c
    ${PCB_CTX_DIR}/src/pcb_ctx_get_app_ctx.c
    ${PCB_CTX_DIR}/src/pcb_ctx_get_krn_ctx.c
)

set(PCB_CTX_HEADERS
    ${PCB_CTX_DIR}/inc
)

# ==============================================================================
# Create source and header for CONTROL
# ==============================================================================
set(PCB_CONTROL_DIR
    ${COMPONENT_NAME}/code/control
)

set(PCB_CONTROL_SOURCES
    # Add the path to each source file here
)

set(PCB_CONTROL_HEADERS
    ${PCB_CONTROL_DIR}/inc
)

# ==============================================================================
# Create source and header for STATE
# ==============================================================================
set(PCB_STATE_DIR
    ${COMPONENT_NAME}/code/state
)

set(PCB_STATE_SOURCES
    # Add the path to each source file here
    ${PCB_STATE_DIR}/src/pcb_state_set_apps_ready.c
    ${PCB_STATE_DIR}/src/pcb_state_get_state.c
)

set(PCB_STATE_HEADERS
    ${PCB_STATE_DIR}/inc
)

# ==============================================================================
# Create source and header for IDENT
# ==============================================================================
set(PCB_IDENT_DIR
    ${COMPONENT_NAME}/code/ident
)

set(PCB_IDENT_SOURCES
    # Add the path to each source file here
)

set(PCB_IDENT_HEADERS
    ${PCB_IDENT_DIR}/inc
)

# ==============================================================================
# Create library kernel target for PCB
# ==============================================================================
set(LIB_NAME_KRN ${PCB_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${PCB_INIT_SOURCES}
        ${PCB_CTX_SOURCES}
        ${PCB_CONTROL_SOURCES}
        ${PCB_STATE_SOURCES}
        ${PCB_IDENT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${PCB_INIT_HEADERS}
        ${PCB_CTX_HEADERS}
        ${PCB_CONTROL_HEADERS}
        ${PCB_STATE_HEADERS}
        ${PCB_IDENT_HEADERS}
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
        ${BMT_LIB_NAME}_krn
        ${ELF_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_usr
        ${MEMORY_LIB_NAME}_krn
        ${BMT_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
