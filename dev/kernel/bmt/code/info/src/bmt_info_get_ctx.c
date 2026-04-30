#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_ctx(void)
{
    return (addr_t)g_p_bmt_ctx_table;
}
