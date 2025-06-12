#include "pcb_krn.h"
#include "pcb_ctx.h"
#include "printer_krn.h"
#include "memory_krn.h"
#include "memory_ops_usr.h"
#include "bmt_krn.h"
#include "elf_krn.h"
#include "strings_utils_usr.h"

bool_t pcb_init()
{
    bool_t init_ok;

    printer_print_string("[KERN] PCB driver initialization ...\n");

    memory_ops_set(&g_pcb_ctx_table, 0, sizeof(g_pcb_ctx_table));
    g_pcb_ctx_table.pcb_krn_ctx.ident.id         = 0;
    g_pcb_ctx_table.pcb_krn_ctx.state            = PCB_STATE_RUNNING;
    g_pcb_ctx_table.pcb_krn_ctx.control.priority = 0;
    g_pcb_ctx_table.pcb_krn_ctx.registers.pc     = bmt_info_get_kernel_entry();
    g_pcb_ctx_table.pcb_krn_ctx.registers.sp     = bmt_info_get_kernel_stack_top();

    /* Allocate the PCB table */
    g_pcb_ctx_table.pcb_apps_ctx = memory_alloc_and_init(sizeof(pcb_ctx_bin_t) * K_BMT_MAX_APP_BINARIES, 0);

    if (g_pcb_ctx_table.pcb_apps_ctx != NULL_PTR)
    {
        /* Initialize the PCB context table */
        g_pcb_ctx_table.pcb_apps_count = bmt_info_get_app_count();

        for (uint32_t i = 0; i < g_pcb_ctx_table.pcb_apps_count; i++)
        {
            g_pcb_ctx_table.pcb_apps_ctx[i].ident.id         = i;
            g_pcb_ctx_table.pcb_apps_ctx[i].state            = PCB_STATE_NEW;
            g_pcb_ctx_table.pcb_apps_ctx[i].control.priority = i;
            g_pcb_ctx_table.pcb_apps_ctx[i].registers.pc     = bmt_info_get_app_entry(i);
            g_pcb_ctx_table.pcb_apps_ctx[i].registers.sp     = bmt_info_get_app_stack_top(i);
        }

        printer_print_string("[KERN] PCB driver initialization done.\n");
        init_ok = TRUE;
    }
    else
    {
        printer_print_string("[KERN] PCB driver initialization failed: PCB context allocation failed.\n");
        init_ok = FALSE;
    }

    return init_ok;
}
