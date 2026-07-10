#ifndef __UART_IRQ_H__
#define __UART_IRQ_H__

/**********************************************************************
 * @brief Interruption ID for UART RX.
 **********************************************************************/
#define K_UART_IRQ_RX_NB    33U


/**********************************************************************
 * @brief UART RX interrupt handler.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void uart_irq_rx(void);


#endif /* __UART_IRQ_H__ */
