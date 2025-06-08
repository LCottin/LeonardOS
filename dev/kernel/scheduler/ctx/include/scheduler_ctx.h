#ifndef __SCHEDULER_CTX_H__
#define __SCHEDULER_CTX_H__

#include "types_usr.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Structure of scheduler context.
 **********************************************************************/
typedef struct
{
    uint32_t scheduler_tasks_id[K_BMT_MAX_APP_BINARIES];
    uint32_t scheduler_current_task_id;
    uint32_t scheduler_nb_tasks;
} scheduler_ctx_table_t;


/**********************************************************************
 * @brief Global structure to store scheduled tasks.
 **********************************************************************/
extern scheduler_ctx_table_t g_scheduler_ctx_table;


/**********************************************************************
 * @brief Get the next task to be scheduled.
 *
 * @param None.
 * @return uint32_t The ID of the next task to be scheduled.
 **********************************************************************/
extern uint32_t scheduler_ctx_get_next_task(void);


/**********************************************************************
 * @brief Get the current task being executed.
 *
 * @param None.
 * @return uint32_t The ID of the current task.
 **********************************************************************/
extern uint32_t scheduler_ctx_get_current_task(void);


/**********************************************************************
 * @brief Set the current task being executed.
 *
 * @param task_id The ID of the task to be set as current.
 * @return None.
 **********************************************************************/
extern void scheduler_ctx_set_current_task(const uint32_t task_id);


#endif /* __SCHEDULER_CTX_H__ */
