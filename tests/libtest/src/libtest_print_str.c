#include "libtest.h"

#define K_UART_BASE_ADDR 0x09000000

static void libtest_print_c(const char_t c)
{
    *(volatile char_t *)K_UART_BASE_ADDR = c;
}

void libtest_print_str(const char_t *str)
{
    while (*str)
    {
        libtest_print_c(*str++);
    }
}
