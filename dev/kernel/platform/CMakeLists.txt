# Build common interface then build platform specific libraries

# ==============================================================================
# Compile common interface library
# ==============================================================================
# build_library(
#     ${PLATFORM_PATH}/common
#     ptf.lib_cmn)

# ==============================================================================
# Compile platform specific libraries
# ==============================================================================
add_subdirectory(${LEONARDOS_PTF})

