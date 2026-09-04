# Define each platform
set(PTF_LIST
)

# ==============================================================================
# Compile platforms
# ==============================================================================
foreach(PTF_NAME ${PTF_LIST})
    build_platform(
        ${PLATFORM_PATH}/${PTF_NAME}
        ${PLATFORM_PREFIX}.lib_${PTF_NAME})
endforeach()
