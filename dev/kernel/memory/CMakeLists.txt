# Define memory modules name
set (MEMORY_LIST
    "heap"
    "tools"
)

# ==============================================================================
# Compile memory modules
# ==============================================================================
foreach(MEMORY_NAME ${MEMORY_LIST})
    build_memory(
        ${MEMORY_PATH}/${MEMORY_NAME}
        ${MEMORY_PREFIX}.lib_${MEMORY_NAME})
endforeach()
