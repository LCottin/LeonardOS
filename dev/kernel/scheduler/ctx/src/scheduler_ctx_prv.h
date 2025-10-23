#ifndef __SCHEDULER_CTX_PRV_H__
#define __SCHEDULER_CTX_PRV_H__

#include "types_usr.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Structure of scheduler context.
 **********************************************************************/
typedef struct
{
    addr_t   scheduler_krn_ctx;
    addr_t   scheduler_apps_ctx[K_BMT_MAX_APP_BINARIES];
    uint32_t scheduler_tasks_id[K_BMT_MAX_APP_BINARIES];
    uint32_t scheduler_current_task_id;
    uint32_t scheduler_nb_tasks;
    uint32_t pad;
} scheduler_ctx_table_t;


/**********************************************************************
 * @brief Global structure to store scheduled tasks.
 **********************************************************************/
extern scheduler_ctx_table_t *g_p_scheduler_ctx_table;


/**********************************************************************
 * @brief Save the current address context.
 *
 * @param sch_start_addr Address to save.
 * @return None.
 **********************************************************************/
extern void scheduler_ctx_save_address(const addr_t sch_start_addr);


#endif /* __SCHEDULER_CTX_PRV_H__ */
