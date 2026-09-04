#ifndef __GIC_CPU_H__
#define __GIC_CPU_H__

/**********************************************************************
 * @brief Start address of the GIC CPU interface.
 **********************************************************************/
#define GICC_BASE_ADDR  0x08010000ULL


/**********************************************************************
 * @brief Offsets of the GIC CPU interface registers.
 **********************************************************************/
#define GICC_CTRL   (GICC_BASE_ADDR + 0x000)
#define GICC_PMR    (GICC_BASE_ADDR + 0x004)
#define GICC_IAR    (GICC_BASE_ADDR + 0x00C)
#define GICC_EOIR   (GICC_BASE_ADDR + 0x010)


#endif /* __GIC_CPU_H__ */
