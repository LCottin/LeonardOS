#ifndef __IRQ_CORE_H__
#define __IRQ_CORE_H__

#include "types_usr.h"
#include "irq_krn.h"


/**********************************************************************
 * @brief Retrieve the registered handler for a specific interrupt ID.
 *
 * @param id The interrupt ID to retrieve the handler for.
 * @return The registered handler function pointer, or NULL if no handler is registered.
 **********************************************************************/
extern irq_handler_t irq_core_get_handler(const uint32_t id);


#endif /* __IRQ_CORE_H__ */
