#ifndef __GIC_DIST_H__
#define __GIC_DIST_H__

#include "types_usr.h"


/**********************************************************************
 * @brief Start address of the GIC dispatcher.
 **********************************************************************/
#define GICD_BASE_ADDR  0x08000000ULL


/**********************************************************************
 * @brief Offsets of the GIC dispatcher registers.
 **********************************************************************/
#define GICD_CTRL           (GICD_BASE_ADDR + 0x000)
#define GICD_ISENABLER(n)   (GICD_BASE_ADDR + 0x100 + ((n) * 4))
#define GICD_ISPENDR(n)     (GICD_BASE_ADDR + 0x200 + ((n) * 4))
#define GICD_IPRIORITYR(n)  (GICD_BASE_ADDR + 0x400 + (n))
#define GICD_ITARGETSR(n)   (GICD_BASE_ADDR + 0x800 + (n))
#define GICD_SGIR           (GICD_BASE_ADDR + 0xF00)

/**********************************************************************
 * @brief Enable a specific interrupt line.
 *
 * @param id The interrupt ID to enable.
 * @return None.
 **********************************************************************/
extern void gic_dist_enable_irq(const uint32_t id);


/**********************************************************************
 * @brief Route a specific interrupt to a CPU or set of CPUs.
 *
 * @param id The interrupt ID to set the priority for.
 * @param cpu_mask A bitmask representing the target CPUs
 * @return None.
 **********************************************************************/
extern void gic_dist_route_to_cpu(const uint32_t id, const uint8_t cpu_mask);


#endif /* __GIC_DIST_H__ */
