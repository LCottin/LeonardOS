#ifndef __SCHEDULER_KRN_H__
#define __SCHEDULER_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Initialize the scheduler.
 *
 * @param None.
 * @return None.
 ***********************************************************************/
extern void scheduler_init(void);


/**********************************************************************
 * @brief Run the scheduler.
 *
 * @param None.
 * @return None.
 ***********************************************************************/
extern void scheduler_run(void);


#endif /* __SCHEDULER_KRN_H__ */
