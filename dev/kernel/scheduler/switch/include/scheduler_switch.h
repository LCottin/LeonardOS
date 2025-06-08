#ifndef __SCHEDULER_SWITCH_H__
#define __SCHEDULER_SWITCH_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Switch the current task in the scheduler.
 *
 * @param is_first_run Indicates if this is the first run of the scheduler.
 * @return None.
 **********************************************************************/
extern void scheduler_switch_task(const bool_t is_first_run);


#endif /* __SCHEDULER_SWITCH_H__ */
