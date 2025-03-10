#ifndef __UART_KRN_H__
#define __UART_KRN_H__

#include "types.h"

/**********************************************************************
 * @brief This function sends a single character to the UART.
 *
 * @param c The character to be sent. This parameter should be a single ASCII character.
 *
 * @return None.
 **********************************************************************/
extern void uart_write_byte(const char_t c);


#endif /* __UART_KRN_H__ */
