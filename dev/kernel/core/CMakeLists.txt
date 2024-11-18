# Ensure objcopy is found and set for binary conversion
find_program(CMAKE_OBJCOPY aarch64-none-elf-objcopy REQUIRED)

# Linker script file path
set(LINKER_SCRIPT ${CORE_DIR}/linker.ld)

# Specify the source file
set(CORE_SOURCES
    ${CORE_DIR}/boot/src/boot.s
    ${CORE_DIR}/MMIO/io8/src/MMIO_io8.c
    ${CORE_DIR}/MMIO/io16/src/MMIO_io16.c
    ${CORE_DIR}/MMIO/io32/src/MMIO_io32.c
    ${CORE_DIR}/MMIO/io64/src/MMIO_io64.c
    ${CORE_DIR}/serial/src/serial.c
    ${CORE_DIR}/syscall/src/syscall.c
    ${CORE_DIR}/UART/src/UART.c
    ${CORE_DIR}/main.c)

set(CORE_HEADERS
    ${CORE_DIR}/MMIO/io8/include/MMIO_io8.h
    ${CORE_DIR}/MMIO/io16/include/MMIO_io16.h
    ${CORE_DIR}/MMIO/io32/include/MMIO_io32.h
    ${CORE_DIR}/MMIO/io64/include/MMIO_io64.h
    ${CORE_DIR}/serial/include/serial.h
    ${CORE_DIR}/syscall/include/syscall.h
    ${CORE_DIR}/UART/include/UART.h)

# Specify the public header directory
set(CORE_INCLUDE
    ${CORE_DIR}/MMIO/io8/include
    ${CORE_DIR}/MMIO/io16/include
    ${CORE_DIR}/MMIO/io32/include
    ${CORE_DIR}/MMIO/io64/include
    ${CORE_DIR}/serial/include
    ${CORE_DIR}/syscall/include
    ${CORE_DIR}/UART/include)

SET(LIB_SYSCALL_SOURCE
    ${CORE_DIR}/syscall/src/syscall.c)

SET(LIB_SYSCALL_HEADERS
    ${CORE_DIR}/syscall/include)

SET(LIB_SYSCALL_PRIVATE
    ${LIB_DIR}/types/include
    ${CORE_DIR}/serial/include)

# Add an executable target
add_executable(${KERNEL_NAME} ${CORE_SOURCES})

# Link header files
foreach(INCLUDE_DIR ${CORE_INCLUDE})
    target_include_directories(${KERNEL_NAME} PRIVATE ${INCLUDE_DIR})
endforeach()

# Ensure the executable is built after the library
add_dependencies(${KERNEL_NAME} ${LIB_MEMORY_NAME})
add_dependencies(${KERNEL_NAME} ${LIB_STRING_NAME})

# Add syscall library
add_library(${LIB_SYSCALL_NAME} STATIC ${LIB_SYSCALL_SOURCE})

# Expose only the public headers for the Syscall library
target_include_directories(${LIB_SYSCALL_NAME}
    PUBLIC ${LIB_SYSCALL_HEADERS}
    PRIVATE ${LIB_SYSCALL_PRIVATE})

# Ensure the lib syscall is built after the kernel
add_dependencies(${LIB_SYSCALL_NAME} ${KERNEL_NAME})

target_sources(${KERNEL_NAME} PRIVATE ${CORE_SOURCES} ${CORE_HEADERS})

# Link the common library
target_link_libraries(${KERNEL_NAME} -Wl,--whole-archive ${LIB_MEMORY_NAME} ${LIB_STRING_NAME})

# Set custom linker options, including the generation of the .map file
target_link_options(${KERNEL_NAME} PRIVATE
                    "-T${LINKER_SCRIPT}"
                    "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${KERNEL_NAME}.map")

