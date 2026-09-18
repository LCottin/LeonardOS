### find our os (wins, centos, ubuntu, etc)
set(VAR_OS "")
IF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(DEBUG "Linux")
    execute_process (
            COMMAND bash -c "awk -F= '/^ID=/{print $2}' /etc/os-release |tr -d '\n' | tr -d '\"'"
            OUTPUT_VARIABLE VAR_OS
    )
    MESSAGE(DEBUG "Linux os: ${VAR_OS}")
ELSEIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(DEBUG "Windows")
    set(VAR_OS "wins")
ELSEIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(DEBUG "Windows")
    set(VAR_OS "mac")
ELSE()
    MESSAGE(FATAL " No OS detected!")
ENDIF(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")

message("-- OS: ${VAR_OS}")

# Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# Set platform used for cross-compilation
set(LEONARDOS_PTF "virt" CACHE STRING "Target platform")
set_property(CACHE LEONARDOS_PTF PROPERTY STRINGS
    "virt"
)

if (LEONARDOS_PTF STREQUAL "virt")
    # Set the architecture and processor for cross-compilation
    set(LEONARDOS_ARCH "aarch64")

    set(CMAKE_SYSTEM_NAME      Generic)
    set(CMAKE_SYSTEM_PROCESSOR ${LEONARDOS_ARCH})
    set(CMAKE_LINKER           aarch64-none-elf-ld)
    set(CMAKE_AR               aarch64-none-elf-ar)
    set(CMAKE_RANLIB           aarch64-none-elf-ranlib)

    find_program(CMAKE_OBJCOPY aarch64-none-elf-objcopy REQUIRED)

    set(PTF_COMPILATION_FLAGS
        "   -target aarch64-none-elf        \
            -march=armv8-a                  \
            -mtune=cortex-a53               \
            -mlittle-endian"
    )
else()
    message(FATAL_ERROR "Unsupported platform: ${LEONARDOS_PTF}")
endif()

# Specify the cross-compiler tools
set(CMAKE_ASM_COMPILER clang)
set(CMAKE_C_COMPILER   clang)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Specify the flags for Clang
set(COMMON_COMPILATION_FLAGS
    "   -Wall                           \
        -Wextra                         \
        -g                              \
        -mgeneral-regs-only             \
        -Wnested-externs                \
        -Wmissing-prototypes            \
        -Wpointer-arith                 \
        -Wcast-qual                     \
        -Wwrite-strings                 \
        -Wshadow                        \
        -Wdeprecated                    \
        -Wundef                         \
        -Wredundant-decls               \
        -Wconversion                    \
        -Wsign-conversion               \
        -Wpadded"
)
set(CMAKE_ASM_FLAGS
    "   ${PTF_COMPILATION_FLAGS}        \
        ${COMMON_COMPILATION_FLAGS}"
)
set(CMAKE_C_FLAGS
    "   ${PTF_COMPILATION_FLAGS}        \
        ${COMMON_COMPILATION_FLAGS}     \
        -std=c17                        \
        -ffreestanding                  \
        -nostdlib                       \
        -fno-builtin                    \
        -fno-common                     \
        -fno-short-enums                \
        -fno-strict-aliasing            \
        -fno-strict-overflow            \
        -fno-delete-null-pointer-checks"
)

# Custom function to build an architecture
function(build_arch ARCH_PATH ARCH_NAME)
    set(ARCH_PATH ${ARCH_PATH} PARENT_SCOPE)
    set(ARCH_NAME ${ARCH_NAME} PARENT_SCOPE)
    add_subdirectory(${ARCH_PATH})
endfunction()

# Custom function to build a binary
function(build_binary BIN_PATH BIN_NAME)
    set(BIN_PATH ${BIN_PATH} PARENT_SCOPE)
    set(BIN_NAME ${BIN_NAME} PARENT_SCOPE)
    add_subdirectory(${BIN_PATH})
endfunction()

# Custom function to build a driver
function(build_driver DRV_PATH DRV_NAME)
    set(DRV_PATH ${DRV_PATH} PARENT_SCOPE)
    set(DRV_NAME ${DRV_NAME} PARENT_SCOPE)
    add_subdirectory(${DRV_PATH})
endfunction()

# Custom function to build a library
function(build_library LIB_PATH LIB_NAME)
    set(LIB_PATH ${LIB_PATH} PARENT_SCOPE)
    set(LIB_NAME ${LIB_NAME} PARENT_SCOPE)
    add_subdirectory(${LIB_PATH})
endfunction()

# Custom function to build a memory module
function(build_memory MEM_PATH MEM_NAME)
    set(MEM_PATH ${MEM_PATH} PARENT_SCOPE)
    set(MEM_NAME ${MEM_NAME} PARENT_SCOPE)
    add_subdirectory(${MEM_PATH})
endfunction()

# Custom function to build a system
function(build_system SYS_PATH SYS_NAME)
    set(SYS_PATH ${SYS_PATH} PARENT_SCOPE)
    set(SYS_NAME ${SYS_NAME} PARENT_SCOPE)
    add_subdirectory(${SYS_PATH})
endfunction()

# Custom function to build a test binary
function(build_test TEST_PATH SRC_PATH TEST_NAME)
    set(TEST_PATH ${TEST_PATH} PARENT_SCOPE)
    set(SRC_PATH  ${SRC_PATH}  PARENT_SCOPE)
    set(TEST_NAME ${TEST_NAME} PARENT_SCOPE)
    add_subdirectory(${TEST_PATH})
endfunction()

# Project name and version
project(LeonardOS LANGUAGES ASM C)

    enable_language(ASM)

    # Output directory for binaries
    set(BIN_DIR      ${CMAKE_BINARY_DIR}/bin)
    set(BIN_DEV_DIR  ${BIN_DIR}/dev)
    set(BIN_TEST_DIR ${BIN_DIR}/test)

    # Define directories
    set(DEV_DIR ${CMAKE_SOURCE_DIR}/dev)

    # Call subdirectories cmake
    add_subdirectory(${DEV_DIR})
