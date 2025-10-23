#include "scheduler_krn.h"
#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"

addr_t scheduler_ctx_get_krn_ctx(void)
{
    return g_p_scheduler_ctx_table->scheduler_krn_ctx;
}
