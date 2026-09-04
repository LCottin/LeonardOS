#ifndef __IRQ_KRN_H__
#define __IRQ_KRN_H__

#include "types_usr.h"


/*****************************************************************************
 * @brief Type definition for an IRQ handler function pointer.
 *****************************************************************************/
typedef void (*irq_handler_t)(void);


/**********************************************************************
 * @brief Initialize the IRQ subsystem, including the GIC and core components.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void irq_core_init(void);


/**********************************************************************
 * @brief Register an IRQ handler for a specific interrupt ID.
 *
 * @param id The interrupt ID to register the handler for.
 * @param handler The function pointer to the handler to be registered.
 * @return None.
 **********************************************************************/
extern void irq_core_register(const uint32_t id, const irq_handler_t handler);


/**********************************************************************
 * @brief Entry point for the IRQ handler.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void irq_handler_entry(void);


#endif /* __IRQ_KRN_H__ */
