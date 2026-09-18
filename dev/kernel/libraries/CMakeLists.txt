# Define libraries name
set (LIBRARY_LIST
    "containers"
    "formatter"
    "libuser"
    "metadata"
    "stream"
    "strings"
)

# ==============================================================================
# Compile libraries
# ==============================================================================
foreach(LIBRARY_NAME ${LIBRARY_LIST})
    build_library(
        ${LIBRARIES_PATH}/${LIBRARY_NAME}
        ${LIBRARIES_PREFIX}.lib_${LIBRARY_NAME})
endforeach()
