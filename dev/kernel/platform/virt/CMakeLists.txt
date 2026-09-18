# Define each platform
set(PTF_LIST
    "boot"
    "core"
)

# ==============================================================================
# Compile platforms
# ==============================================================================
foreach(PTF_NAME ${PTF_LIST})
    build_binary(
        ${PLATFORM_PATH}/${LEONARDOS_PTF}/${PTF_NAME}
        ${PTF_NAME}_bin)
endforeach()
