#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_app_entry(const uint32_t app_id)
{
    addr_t entry_point;

    if (app_id < g_p_bmt_ctx_table->apps_count)
    {
        entry_point = g_p_bmt_ctx_table->apps_bin[app_id].entry_point;
    }
    else
    {
        /* Invalid app_id, return NULL */
        entry_point = NULL_ADDR;
    }

    return entry_point;
}
