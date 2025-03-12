#ifndef __CLOCK_KRN_H__
#define __CLOCK_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Initializes the time management system.
 *
 * This function initializes the time management system, setting up
 * any necessary hardware timers or counters.
 *
 * @return None.
 **********************************************************************/
extern void clock_init(void);


/**********************************************************************
 * @brief Gets the current time.
 *
 * This function returns the current time since the system started.
 *
 * @return The current time.
 **********************************************************************/
extern time_t clock_info_get_time(void);


#endif /* __CLOCK_KRN_H__ */
