# Specify the source file
set(COMMON_SOURCES
    ${COMMON_DIR}/memory/src/memory.c
    ${COMMON_DIR}/stdlib/src/stdlib.c
    ${COMMON_DIR}/string/src/string.c)

# Specify the public header file
set(COMMON_DIR
    ${COMMON_DIR}/memory/include/
    ${COMMON_DIR}/stdlib/include/
    ${COMMON_DIR}/string/include/
    ${COMMON_DIR}/types/include/)

# Add a library target
add_library(${LIB_COMMON_NAME} STATIC ${COMMON_SOURCES})

# Link header files
target_include_directories(${LIB_COMMON_NAME} PUBLIC ${COMMON_DIR})
