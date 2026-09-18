# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(SCHEDULER_INIT_DIR
    ${SYS_PATH}/code/init
)

set(SCHEDULER_INIT_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_INIT_DIR}/src/scheduler_init.c
)

set(SCHEDULER_INIT_HEADERS
    ${SCHEDULER_INIT_DIR}/inc
)

# ==============================================================================
# Create source and header for RUN
# ==============================================================================
set(SCHEDULER_RUN_DIR
    ${SYS_PATH}/code/run
)

set(SCHEDULER_RUN_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_RUN_DIR}/src/scheduler_run.c
)

set(SCHEDULER_RUN_HEADERS
    ${SCHEDULER_RUN_DIR}/inc
)

# ==============================================================================
# Create source and header for SWITCH
# ==============================================================================
set(SCHEDULER_SWITCH_DIR
    ${SYS_PATH}/code/switch
)

set(SCHEDULER_SWITCH_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_SWITCH_DIR}/src/scheduler_switch_first_task.S
    ${SCHEDULER_SWITCH_DIR}/src/scheduler_switch_next_task.S
)

set(SCHEDULER_SWITCH_HEADERS
    ${SCHEDULER_SWITCH_DIR}/inc
)

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(SCHEDULER_CTX_DIR
    ${SYS_PATH}/code/ctx
)

set(SCHEDULER_CTX_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_data.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_current_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_next_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_task_count.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_app_ctx.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_krn_ctx.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_set_current_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_add_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_init.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_save_address.S
)

set(SCHEDULER_CTX_HEADERS
    ${SCHEDULER_CTX_DIR}/inc
)


# ==============================================================================
# Create library target for SCHEDULER
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source directory here
        ${SCHEDULER_INIT_SOURCES}
        ${SCHEDULER_RUN_SOURCES}
        ${SCHEDULER_SWITCH_SOURCES}
        ${SCHEDULER_CTX_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${SCHEDULER_INIT_HEADERS}
        ${SCHEDULER_RUN_HEADERS}
        ${SCHEDULER_SWITCH_HEADERS}
        ${SCHEDULER_CTX_HEADERS}
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
        system.lib_pcb
        memory.lib_tools
        system.lib_printer
        libraries.lib_strings
        libraries.lib_formatter
        libraries.lib_stream
        libraries.lib_metadata
)
