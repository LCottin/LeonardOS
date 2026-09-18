# Define system name
set (SYSTEM_LIST
    "bmt"
    "clock"
    "elf"
    "pcb"
    "printer"
    "scheduler"
    "syscall"
)

# ==============================================================================
# Compile system modules
# ==============================================================================
foreach(SYSTEM_NAME ${SYSTEM_LIST})
    build_system(
        ${SYSTEM_PATH}/${SYSTEM_NAME}
        ${SYSTEM_PREFIX}.lib_${SYSTEM_NAME})
endforeach()
