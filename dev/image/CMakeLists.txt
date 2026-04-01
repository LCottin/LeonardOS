# ==============================================================================
# Set the output directory of the executable
# ==============================================================================
set(FLASH_IMG_NAME      "flash")
set(RPI_IMG_NAME        "RPI")
set(BOOT_FLASH_IMG_NAME "boot_flash")

set(FLASH_IMG_PATH      ${BIN_DEV_DIR}/${FLASH_IMG_NAME}.img)
set(FLASH_OBJ_PATH      ${BIN_DEV_DIR}/${FLASH_IMG_NAME}.o)
set(BOOT_FLASH_ELF      ${BIN_DEV_DIR}/${BOOT_FLASH_IMG_NAME}.elf)
set(BOOT_FLASH_BIN      ${BIN_DEV_DIR}/${BOOT_FLASH_IMG_NAME}.img)
set(RPI_IMG_PATH        ${BIN_DEV_DIR}/${RPI_IMG_NAME}.img)
set(CORE_PATH          "${BIN_DEV_DIR}/core_bin/core_bin.elf")
set(APP1_PATH          "${BIN_DEV_DIR}/hello_world/hello_world.elf")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DEV_DIR})
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld)

# ==========================================================
# FLASH IMAGE
# ==========================================================
add_custom_command(
    OUTPUT ${FLASH_IMG_PATH}
    COMMAND ${CMAKE_COMMAND} -E echo "Generating flash image"
    COMMAND ${CMAKE_COMMAND} -E remove -f ${FLASH_IMG_PATH}
    COMMAND ${CMAKE_COMMAND} -E cat ${CORE_PATH} ${APP1_PATH} > ${FLASH_IMG_PATH}
    DEPENDS ${CORE_PATH} ${APP1_PATH}
)

add_custom_target(flash DEPENDS ${FLASH_IMG_PATH})

# ==========================================================
# CONVERT FLASH IMAGE TO OBJECT
# ==========================================================
add_custom_command(
    OUTPUT ${FLASH_OBJ_PATH}
    COMMAND ${CMAKE_OBJCOPY}
            -I binary
            -O elf64-littleaarch64
            -B aarch64
            ${FLASH_IMG_PATH}
            ${FLASH_OBJ_PATH}
    COMMAND ${CMAKE_OBJCOPY}
            --rename-section .data=.flash,alloc,load,readonly,data,contents
            ${FLASH_OBJ_PATH}
    DEPENDS ${FLASH_IMG_PATH}
)

add_custom_target(flash_obj DEPENDS ${FLASH_OBJ_PATH})

# ==========================================================
# BOOT WITH EMBEDDED FLASH
# ==========================================================
file(WRITE ${CMAKE_BINARY_DIR}/dummy.c "")

add_executable(${BOOT_FLASH_IMG_NAME}.elf
    ${CMAKE_BINARY_DIR}/dummy.c
    ${FLASH_OBJ_PATH}
)

add_dependencies(${BOOT_FLASH_IMG_NAME}.elf flash_obj)

target_link_libraries(${BOOT_FLASH_IMG_NAME}.elf
    PRIVATE
        "-Wl,--whole-archive"
        ${BOOT_LIB_NAME}_krn
        "-Wl,--no-whole-archive"
)

target_link_options(${BOOT_FLASH_IMG_NAME}.elf
    PRIVATE
        "-T${LINKER_SCRIPT}"
        "-nostdlib"
        "-Wl,-Map,${CMAKE_BINARY_DIR}/${BOOT_FLASH_IMG_NAME}.map"
)

# ==========================================================
# FINAL RASPBERRY PI IMAGE
# ==========================================================

add_custom_command(
    OUTPUT ${RPI_IMG_PATH}
    COMMAND ${CMAKE_OBJCOPY}
            -O binary
            ${BOOT_FLASH_ELF}
            ${RPI_IMG_PATH}
    DEPENDS ${BOOT_FLASH_ELF}
)

add_custom_target(rpi_image ALL DEPENDS ${RPI_IMG_PATH})
