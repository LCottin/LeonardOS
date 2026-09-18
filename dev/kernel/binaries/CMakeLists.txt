# Define binaries name
set (BINARY_LIST
    "core"
    "boot"
)

# ==============================================================================
# Compile system modules
# ==============================================================================
foreach(BINARY_NAME ${BINARY_LIST})
    build_binary(
        ${BINARIES_PATH}/${BINARY_NAME}
        ${BINARY_NAME}_bin)
endforeach()
