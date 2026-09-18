# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(PCB_INIT_DIR
    ${SYS_PATH}/code/init
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
    ${SYS_PATH}/code/ctx
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
    ${SYS_PATH}/code/control
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
    ${SYS_PATH}/code/state
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
    ${SYS_PATH}/code/ident
)

set(PCB_IDENT_SOURCES
    # Add the path to each source file here
)

set(PCB_IDENT_HEADERS
    ${PCB_IDENT_DIR}/inc
)

# ==============================================================================
# Create library target for PCB
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source file here
        ${PCB_INIT_SOURCES}
        ${PCB_CTX_SOURCES}
        ${PCB_CONTROL_SOURCES}
        ${PCB_STATE_SOURCES}
        ${PCB_IDENT_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${PCB_INIT_HEADERS}
        ${PCB_CTX_HEADERS}
        ${PCB_CONTROL_HEADERS}
        ${PCB_STATE_HEADERS}
        ${PCB_IDENT_HEADERS}
    PUBLIC
        ${SYS_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${SYS_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        system.lib_bmt
        system.lib_elf
        system.lib_printer
        memory.lib_tools
        memory.lib_heap
        libraries.lib_strings
        libraries.lib_formatter
        libraries.lib_stream
        libraries.lib_metadata
)
