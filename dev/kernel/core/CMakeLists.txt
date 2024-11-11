# Ensure objcopy is found and set for binary conversion
find_program(CMAKE_OBJCOPY aarch64-none-elf-objcopy REQUIRED)

# Linker script file path
set(LINKER_SCRIPT ${CORE_DIR}/linker.ld)

# Specify the source file
set(CORE_SOURCES
    ${CORE_DIR}/boot/src/boot.s
    ${CORE_DIR}/serial_print/src/serial_print.c
    ${CORE_DIR}/UART/src/UART.c
    ${CORE_DIR}/main.c)

set(CORE_HEADERS
    ${CORE_DIR}/serial_print/include/serial_print.h
    ${CORE_DIR}/UART/include/UART.h)

# Specify the public header directory
set(CORE_INCLUDE
    ${CORE_DIR}/serial_print/include
    ${CORE_DIR}/UART/include)

# Add an executable target
add_executable(${KERNEL_NAME} ${CORE_SOURCES})

# Link header files
foreach(INCLUDE_DIR ${CORE_INCLUDE})
    target_include_directories(${KERNEL_NAME} PRIVATE ${INCLUDE_DIR})
endforeach()

# Ensure the executable is built after the library
add_dependencies(${KERNEL_NAME} ${LIB_MEMORY_NAME})
add_dependencies(${KERNEL_NAME} ${LIB_STRING_NAME})

target_sources(${KERNEL_NAME} PRIVATE ${CORE_SOURCES} ${CORE_HEADERS})

# Link the common library
target_link_libraries(${KERNEL_NAME} -Wl,--whole-archive ${LIB_MEMORY_NAME} ${LIB_STRING_NAME})

# Set custom linker options, including the generation of the .map file
target_link_options(${KERNEL_NAME} PRIVATE
                    "-T${LINKER_SCRIPT}"
                    "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${KERNEL_NAME}.map")

# Add a custom target to create the binary image
add_custom_target(elf_to_bin ALL
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${KERNEL_NAME}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${KERNEL_NAME}.img
    DEPENDS ${KERNEL_NAME}
    COMMENT "Converting ELF to binary image")
