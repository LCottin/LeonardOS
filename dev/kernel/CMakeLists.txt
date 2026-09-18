### Build arch ###
set(ARCHITECTURE_PREFIX "arch")
set(ARCHITECTURE_PATH   ${KERNEL_DIR}/arch)
add_subdirectory(${ARCHITECTURE_PATH})

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
set(PLATFORM_PATH   ${KERNEL_DIR}/platform)
add_subdirectory(${PLATFORM_PATH})

### Build system ###
set(SYSTEM_PREFIX "system")
set(SYSTEM_PATH   ${KERNEL_DIR}/system)
add_subdirectory(${SYSTEM_PATH})

### Build tests ###
include(tests.cmake)
