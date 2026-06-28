#include "bmt_ctx.h"
#include "bmt_krn.h"
#include "printer_krn.h"
#include "strings_utils_usr.h"

void bmt_info_print_table(void)
{
    /* Print the kernel binary information */
    printer_print_string("Kernel binary information:\n");
    printer_print_formatted("    Kernel entry point:          %x\n",   g_p_bmt_ctx_table->krn_bin.entry_point);
    printer_print_formatted("    Kernel load address:         %x\n",   g_p_bmt_ctx_table->krn_bin.load_address);
    printer_print_formatted("    Kernel segments count:       %d\n",   g_p_bmt_ctx_table->krn_bin.segments_count);
    printer_print_formatted("    Kernel compatibility status: %s\n",   g_p_bmt_ctx_table->krn_bin.is_compatible ? "Compatible" : "Incompatible");
    printer_print_formatted("    Kernel stack top:            %x\n",   g_p_bmt_ctx_table->krn_bin.memory_info.stack_top);
    printer_print_formatted("    Kernel stack size:           %x\n",   g_p_bmt_ctx_table->krn_bin.memory_info.stack_size);
    printer_print_formatted("    Kernel heap start:           %x\n",   g_p_bmt_ctx_table->krn_bin.memory_info.heap_start);
    printer_print_formatted("    Kernel heap size:            %x\n\n", g_p_bmt_ctx_table->krn_bin.memory_info.heap_size);
    printer_print_formatted("App binary information:%d\n",             g_p_bmt_ctx_table->apps_count);

    /* Loop through all the applications in the bmt table */
    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->apps_count; idx++)
    {
        const ELF64_binary_info_t *p_app_bin = &g_p_bmt_ctx_table->apps_bin[idx];

        printer_print_formatted("\nApplication binary ID: %d\n", idx);
        printer_print_formatted("    Application entry point:          %x\n",   p_app_bin->entry_point);
        printer_print_formatted("    Application load address:         %x\n",   p_app_bin->load_address);
        printer_print_formatted("    Application segments count:       %x\n",   p_app_bin->segments_count);
        printer_print_formatted("    Application compatibility status: %s\n",   p_app_bin->is_compatible ? "Compatible" : "Incompatible");
        printer_print_formatted("    Application stack top:            %x\n",   p_app_bin->memory_info.stack_top);
        printer_print_formatted("    Application stack size:           %x\n",   p_app_bin->memory_info.stack_size);
        printer_print_formatted("    Application heap start:           %d\n",   p_app_bin->memory_info.heap_start);
        printer_print_formatted("    Application heap size:            %x\n\n", p_app_bin->memory_info.heap_size);
    }

    printer_print_string("\n");
}
