#include "pcb_krn.h"
#include "pcb_ctx.h"
#include "serial_krn.h"
#include "memory_krn.h"
#include "memory_ops_usr.h"
#include "bmt_krn.h"
#include "elf_krn.h"
#include "strings_utils_usr.h"

bool_t pcb_init(const addr_t bmt_start_addr)
{
    bool_t init_ok;

    serial_print_string("[KERN] PCB driver initialization ...\n");

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
        const bmt_ctx_table_t *p_bmt_table = (const bmt_ctx_table_t *)bmt_start_addr;
        g_pcb_ctx_table.pcb_apps_count     = p_bmt_table->apps_count; // faire un accesseur sur le bmt

        for (uint32_t i = 0; i < g_pcb_ctx_table.pcb_apps_count; i++)
        {
            g_pcb_ctx_table.pcb_apps_ctx[i].ident.id         = i;
            g_pcb_ctx_table.pcb_apps_ctx[i].state            = PCB_STATE_NEW;
            g_pcb_ctx_table.pcb_apps_ctx[i].control.priority = i;
            g_pcb_ctx_table.pcb_apps_ctx[i].registers.pc     = bmt_info_get_app_entry(i);
            g_pcb_ctx_table.pcb_apps_ctx[i].registers.sp     = bmt_info_get_app_stack_top(i);

            char str[32];
            serial_print_string("[KERN] PCB context app entry: ");
            serial_print_string(string_utils_itoa((int32_t)g_pcb_ctx_table.pcb_apps_ctx[i].registers.pc, str, 10U));
            serial_print_string(" \n");
            memory_ops_set(str, 0, 32);
            serial_print_string("[KERN] PCB context app stack: ");
            serial_print_string(string_utils_itoa((int32_t)g_pcb_ctx_table.pcb_apps_ctx[i].registers.sp, str, 10U));
            serial_print_string(" \n");
        }

        serial_print_string("[KERN] PCB driver initialization done.\n");
        init_ok = TRUE;
    }
    else
    {
        serial_print_string("[KERN] PCB driver initialization failed: PCB context allocation failed.\n");
        init_ok = FALSE;
    }

    return init_ok;
}
