#include "pcb_ctx.h"
#include "pcb_ctx_prv.h"

void pcb_ctx_krn_save(void)
{
    /* Save the kernel context */
    pcb_ctx_save(&g_pcb_ctx_table.pcb_krn_ctx.registers);
}
