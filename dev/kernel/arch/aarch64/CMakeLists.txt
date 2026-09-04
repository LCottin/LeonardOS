# Define each architecture
set(ARCH_LIST
    "fpu"
    "irq"
    "seh"
)

# Build types library, library dependant on architecture
build_library(
    ${ARCHITECTURE_PATH}/types
    arch.lib_types)

# ==============================================================================
# Compile architectures
# ==============================================================================
foreach(ARCH_NAME ${ARCH_LIST})
    build_arch(
        ${ARCHITECTURE_PATH}/${ARCH_NAME}
        ${ARCHITECTURE_PREFIX}.lib_${ARCH_NAME})
endforeach()
