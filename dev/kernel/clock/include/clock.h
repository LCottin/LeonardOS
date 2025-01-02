#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "types.h"

/**
 * @brief Initializes the time management system.
 *
 * This function initializes the time management system, setting up
 * any necessary hardware timers or counters.
 *
 * @return None.
 */
extern void clock_init(void);

/**
 * @brief Gets the current time.
 *
 * This function returns the current time since the system started.
 *
 * @return The current time.
 */
extern time_t clock_get_time(void);

#endif /* __CLOCK_H__ */
