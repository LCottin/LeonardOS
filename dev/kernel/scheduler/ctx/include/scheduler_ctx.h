#ifndef __SCHEDULER_CTX_H__
#define __SCHEDULER_CTX_H__

#include "types_usr.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Get the next task to be scheduled.
 *
 * @param None.
 * @return uint32_t The ID of the next task to be scheduled.
 **********************************************************************/
extern uint32_t scheduler_ctx_get_next_task(void);


/**********************************************************************
 * @brief Set the current task being executed.
 *
 * @param task_id The ID of the task to be set as current.
 * @return None.
 **********************************************************************/
extern void scheduler_ctx_set_current_task(const uint32_t task_id);


/**********************************************************************
 * @brief Initialize the scheduler context.
 *
 * @param sch_start_addr The starting address for the scheduler context.
 * @return None.
 **********************************************************************/
extern void scheduler_ctx_init(const addr_t sch_start_addr);


/**********************************************************************
 * @brief Add a new task to the scheduler context.
 *
 * @param task_idx The index of the task to be added.
 * @return None.
 **********************************************************************/
extern void scheduler_ctx_add_task(const uint32_t task_idx);


extern addr_t scheduler_ctx_get_krn_ctx(void);
extern addr_t scheduler_ctx_get_app_ctx(const uint32_t task_id);

#endif /* __SCHEDULER_CTX_H__ */
