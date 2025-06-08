#ifndef __SCHEDULER_CTX_PRV_H__
#define __SCHEDULER_CTX_PRV_H__

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


#endif /* __SCHEDULER_CTX_PRV_H__ */
