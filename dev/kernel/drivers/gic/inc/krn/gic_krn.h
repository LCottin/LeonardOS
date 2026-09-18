#ifndef __GIC_KRN_H__
#define __GIC_KRN_H__

#include "types_usr.h"


/**************************************************************
 * @brief Initialize the GIC component
 *
 * @param None.
 * @return None.
 **************************************************************/
extern void gic_init(void);


/**************************************************************
 * @brief Register the end of the interrupt handling
 *
 * @param id The interrupt ID
 * @return None.
 **************************************************************/
extern void gic_cpu_eoi(const uint32_t id);


/**************************************************************
 * @brief Acknowledge the current interrupt and retrieve its ID
 *
 * @param None.
 * @return The ID of the acknowledged interrupt.
 **************************************************************/
extern uint32_t gic_cpu_ack(void);


/**************************************************************
 * @brief Initialize a specific interrupt line
 *
 * @param id The interrupt ID to initialize.
 * @return None.
 **************************************************************/
extern void gic_init_irq(const uint32_t id);


/**************************************************************
 * @brief Set the priority of a specific interrupt line
 *
 * @param id The interrupt ID to set the priority for.
 * @param prio The priority level to set (0-255, where 0 is the highest priority).
 * @return None.
 **************************************************************/
extern void gic_cpu_set_priority(const uint32_t id, const uint8_t prio);


/**************************************************************
 * @brief Send a Software Generated Interrupt (SGI) to target CPUs
 *
 * @param id The SGI ID to send (0-15).
 * @return None.
 **************************************************************/
extern void gic_sgi_send(const uint32_t id);

#endif /* __GIC_KRN_H__ */
