#ifndef __CLOCK_INFO_H__
#define __CLOCK_INFO_H__

#include "types.h"

/**********************************************************************
 * @brief Gets the frequency of the time source.
 *
 * This function returns the frequency of the time source used by the
 * time management system.
 *
 * @return The frequency of the time source.
 **********************************************************************/
extern uint64_t clock_info_get_frequency(void);


/**********************************************************************
 * @brief Gets the current cycle count.
 *
 * This function returns the current cycle count from the hardware timer
 * or counter.
 *
 * @return The current cycle count.
 **********************************************************************/
extern uint64_t clock_info_get_cycle_count(void);


#endif /* __CLOCK_INFO_H__ */
