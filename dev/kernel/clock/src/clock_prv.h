#ifndef __CLOCK_PRV_H__
#define __CLOCK_PRV_H__

#include "types.h"

/**
 * @brief Gets the frequency of the time source.
 *
 * This function returns the frequency of the time source used by the
 * time management system.
 *
 * @return The frequency of the time source.
 */
extern uint64_t clock_get_frequency(void);

/**
 * @brief Gets the current cycle count.
 *
 * This function returns the current cycle count from the hardware timer
 * or counter.
 *
 * @return The current cycle count.
 */
extern uint64_t clock_get_cycle_count(void);

/**
 * @brief The frequency of the time source.
 *
 * This variable holds the frequency of the time source used by the
 * time management system.
 */
extern uint64_t g_clock_frequency;

#endif /* __CLOCK_PRV_H__ */
