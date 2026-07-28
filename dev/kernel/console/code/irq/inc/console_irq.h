#ifndef __CONSOLE_IRQ_H__
#define __CONSOLE_IRQ_H__

/**********************************************************************
 * @brief Interruption ID for console RX.
 **********************************************************************/
#define K_CONSOLE_IRQ_RX_NB    33U


/**********************************************************************
 * @brief UART RX interrupt handler.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void console_irq_rx(void);


#endif /* __CONSOLE_IRQ_H__ */
