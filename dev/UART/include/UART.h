#ifndef __UART_H__
#define __UART_H__

/**
 * @brief This function sends a single character to the UART.
 *
 * @param c The character to be sent. This parameter should be a single ASCII character.
 *
 * @return None.
 */
extern void UARTSendByte(const char c);

#endif /* __UART_H__ */