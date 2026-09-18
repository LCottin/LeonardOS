# Define drivers name
set (DRIVERS_LIST
    "console"
    "gic"
    "mmio"
    "uart"
)

# ==============================================================================
# Compile drivers
# ==============================================================================
foreach(DRIVER_NAME ${DRIVERS_LIST})
    build_driver(
        ${DRIVERS_PATH}/${DRIVER_NAME}
        ${DRIVERS_PREFIX}.lib_${DRIVER_NAME})
endforeach()
