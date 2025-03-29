#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_app_stack_top(const uint32_t app_id)
{
    addr_t stack_top;

    if (app_id < g_p_bmt_ctx_table->apps_count)
    {
        stack_top = g_p_bmt_ctx_table->apps_bin[app_id].memory_info.stack_top;
    }
    else
    {
        /* Invalid app_id, return NULL */
        stack_top = NULL_ADDR;
    }

    return stack_top;
}
