#ifndef __SCHEDULER_KRN_H__
#define __SCHEDULER_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Initialize the scheduler.
 *
 * @param sch_start_addr Start address of the SCH region.
 * @return None.
 ***********************************************************************/
extern void scheduler_init(const addr_t sch_start_addr);


/**********************************************************************
 * @brief Run the scheduler.
 *
 * @param None.
 * @return None.
 ***********************************************************************/
extern void scheduler_run(void);


/**********************************************************************
 * @brief Get the current task being executed.
 *
 * @param None.
 * @return uint32_t The ID of the current task.
 **********************************************************************/
extern uint32_t scheduler_ctx_get_current_task(void);


/**********************************************************************
 * @brief Switch to the next task in the scheduler.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void scheduler_switch_next_task(void);


/**********************************************************************
 * @brief Get number of tasks managed by the scheduler.
 *
 * @param None.
 * @return uint32_t The number of tasks.
 **********************************************************************/
extern uint32_t scheduler_ctx_get_task_count(void);


#endif /* __SCHEDULER_KRN_H__ */
