# Define binaries name
set (BINARY_LIST
    "core"
    "boot"
)

# ==============================================================================
# Compile system modules
# ==============================================================================
foreach(BINARY_NAME ${BINARY_LIST})
    build_library(
        ${BINARIES_PATH}/${BINARY_NAME}
        ${BINARIES_PREFIX}.lib_${BINARY_NAME})

    build_binary(
        ${BINARIES_PATH}/${BINARY_NAME}_bin
        ${BINARIES_PREFIX}.${BINARY_NAME})
endforeach()
