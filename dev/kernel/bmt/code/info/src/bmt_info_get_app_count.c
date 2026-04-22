#include "bmt_krn.h"
#include "bmt_ctx.h"

uint32_t bmt_info_get_app_count(void)
{
    return g_p_bmt_ctx_table->apps_count;
}
