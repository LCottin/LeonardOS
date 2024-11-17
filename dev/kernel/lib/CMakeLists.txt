
set(LIB_CONTAINERS_DIR ${LIB_DIR}/containers)
set(LIB_MEMORY_DIR ${LIB_DIR}/memory)
set(LIB_STRING_DIR ${LIB_DIR}/string)

# Call subdirectories cmake
add_subdirectory(${LIB_CONTAINERS_DIR})
add_subdirectory(${LIB_MEMORY_DIR})
add_subdirectory(${LIB_STRING_DIR})
