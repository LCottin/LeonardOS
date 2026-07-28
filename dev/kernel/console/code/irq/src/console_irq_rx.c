#include "uart_krn.h"
#include "console_krn.h"
#include "console_irq.h"

void console_irq_rx(void)
{
    const char_t c = uart_read_byte();
    console_buffer_push(c);
}
