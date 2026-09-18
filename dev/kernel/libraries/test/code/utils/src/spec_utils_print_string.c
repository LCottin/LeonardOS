#include "spec_utils_krn.h"
#include "spec_utils_prv.h"

void spec_utils_print_string(const char_t *str)
{
    while (*str != '\0')
    {
        *((volatile char_t *)K_QEMU_UART_BASE) = *str++;
    }
}
