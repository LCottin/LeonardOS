# Build common interface then build architecture specific libraries

# ==============================================================================
# Compile common interface library
# ==============================================================================
build_library(
    ${ARCHITECTURE_PATH}/common
    arch.lib_cmn)

# ==============================================================================
# Compile architectures specific libraries
# ==============================================================================
add_subdirectory(${LEONARDOS_ARCH})
