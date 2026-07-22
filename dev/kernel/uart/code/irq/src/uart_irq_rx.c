#include "uart_irq.h"
#include "uart_krn.h"
#include "console_krn.h"

void uart_irq_rx(void)
{
    char* t = "rcv uart";
    while (*t)
        uart_write_byte(*t++);
    const char_t c = uart_read_byte();
    console_buffer_push(c);
}
