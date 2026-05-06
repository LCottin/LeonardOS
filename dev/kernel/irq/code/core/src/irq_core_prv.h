#ifndef __IRQ_CORE_PRV_H__
#define __IRQ_CORE_PRV_H__

#include "irq_krn.h"


/*****************************************************************************
 * @brief Maximum number of IRQs supported by the system.
 *****************************************************************************/
#define K_IRQ_CORE_MAX_IRQ 256


/*****************************************************************************
 * @brief Array to hold the registered IRQ handlers.
 *****************************************************************************/
extern irq_handler_t g_irq_handlers[K_IRQ_CORE_MAX_IRQ];


#endif /* __IRQ_CORE_PRV_H__ */
