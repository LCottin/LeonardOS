#ifndef __UART_KRN_H__
#define __UART_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief This function initializes the UART context.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void uart_ctx_init(void);


/**********************************************************************
 * @brief This function sends a single character to the UART.
 *
 * @param c The character to be sent. This parameter should be a single ASCII character.
 *
 * @return None.
 **********************************************************************/
extern void uart_write_byte(const char_t c);


/**********************************************************************
 * @brief This function reads a single character from the UART.
 *
 * @param None.
 * @return The character read from the UART, or -1 if not available.
 **********************************************************************/
extern char_t uart_read_byte(void);


#endif /* __UART_KRN_H__ */
