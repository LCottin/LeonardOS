#include "pcb_ctx.h"
#include "pcb_krn.h"

addr_t pcb_ctx_get_krn_ctx(void)
{
    return (addr_t)&g_pcb_ctx_table.pcb_krn_ctx;
}
