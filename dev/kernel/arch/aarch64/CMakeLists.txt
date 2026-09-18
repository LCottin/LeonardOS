# Define each architecture
set(ARCH_LIST
    "entry"
    "fpu"
    "irq"
    "seh"
)

# Build types library, library dependant on architecture
build_library(
    ${ARCHITECTURE_PATH}/${LEONARDOS_ARCH}/types
    arch.lib_types)

# ==============================================================================
# Compile architectures
# ==============================================================================
foreach(ARCH_NAME ${ARCH_LIST})
    build_arch(
        ${ARCHITECTURE_PATH}/${LEONARDOS_ARCH}/${ARCH_NAME}
        ${ARCHITECTURE_PREFIX}.lib_${ARCH_NAME})
endforeach()
