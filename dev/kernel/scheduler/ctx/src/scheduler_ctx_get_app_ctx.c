#include "scheduler_krn.h"
#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"

addr_t scheduler_ctx_get_app_ctx(const uint32_t task_id)
{
    addr_t app_ctx;

    if (task_id < g_p_scheduler_ctx_table->scheduler_nb_tasks)
    {
        app_ctx = g_p_scheduler_ctx_table->scheduler_apps_ctx[task_id];
    }
    else
    {
        app_ctx =  NULL_ADDR;
    }

    return app_ctx;
}
