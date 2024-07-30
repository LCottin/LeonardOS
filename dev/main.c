#define QEMU_UART_ADDR 0x09000000

void main()
{
    *((volatile unsigned int *)QEMU_UART_ADDR) = '[';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'M';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'A';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'I';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'N';
    *((volatile unsigned int *)QEMU_UART_ADDR) = ']';
    *((volatile unsigned int *)QEMU_UART_ADDR) = ' ';

    *((volatile unsigned int *)QEMU_UART_ADDR) = 'H';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'e';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'l';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'l';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'o';

    *((volatile unsigned int *)QEMU_UART_ADDR) = ' ';

    *((volatile unsigned int *)QEMU_UART_ADDR) = 'w';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'o';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'r';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'l';
    *((volatile unsigned int *)QEMU_UART_ADDR) = 'd';

    *((volatile unsigned int *)QEMU_UART_ADDR) = '!';

    while(1) ;
}