### Build arch ###
set(ARCHITECTURE_PREFIX "arch")
set(ARCHITECTURE_PATH   ${KERNEL_DIR}/arch/${LEONARDOS_ARCH})
add_subdirectory(${ARCHITECTURE_PATH})

### Build binaries ###
set(BINARIES_PREFIX "binaries")
set(BINARIES_PATH   ${KERNEL_DIR}/binaries)
add_subdirectory(${BINARIES_PATH})

### Build drivers ###
set(DRIVERS_PREFIX "drivers")
set(DRIVERS_PATH   ${KERNEL_DIR}/drivers)
add_subdirectory(${DRIVERS_PATH})

### Build libraries ###
set(LIBRARIES_PREFIX "libraries")
set(LIBRARIES_PATH   ${KERNEL_DIR}/libraries)
add_subdirectory(${LIBRARIES_PATH})

### Build memory ###
set(MEMORY_PREFIX "memory")
set(MEMORY_PATH   ${KERNEL_DIR}/memory)
add_subdirectory(${MEMORY_PATH})

### Build platform ###
set(PLATFORM_PREFIX "platform")
set(PLATFORM_PATH   ${KERNEL_DIR}/platform/${LEONARDOS_PTF})
add_subdirectory(${PLATFORM_PATH})

### Build system ###
set(SYSTEM_PREFIX "system")
set(SYSTEM_PATH   ${KERNEL_DIR}/system)
add_subdirectory(${SYSTEM_PATH})

### Build tests ###
include(tests.cmake)
