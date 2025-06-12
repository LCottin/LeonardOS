#include "bmt_ctx.h"
#include "bmt_krn.h"
#include "printer_krn.h"
#include "strings_utils_usr.h"

void bmt_info_print_table(void)
{
    /* Print the kernel binary information */
    printer_print_string("Kernel binary information:\n");
    printer_print_string("    Kernel entry point:          0x");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.entry_point, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    printer_print_string("    Kernel load address:         0x");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.load_address, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    printer_print_string("    Kernel segments count:       ");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.segments_count, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    printer_print_string("    Kernel compatibility status: ");
    printer_print_string(g_p_bmt_ctx_table->krn_bin.is_compatible ? "Compatible\n" : "Incompatible\n");

    printer_print_string("    Kernel stack top:            0x");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.stack_top, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    printer_print_string("    Kernel stack size:           ");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.stack_size, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    printer_print_string("    Kernel heap start:           0x");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.heap_start, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    printer_print_string("    Kernel heap size:            ");
    printer_print_int((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.heap_size, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n\n");

    printer_print_string("App binary information:\n");
    printer_print_string("    App binary count: ");
    printer_print_int((int32_t)g_p_bmt_ctx_table->apps_count, PRINTER_BASE_HEXADECIMAL);
    printer_print_string("\n");

    /* Loop through all the applications in the bmt table */
    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->apps_count; idx++)
    {
        const ELF64_binary_info_t *p_app_bin = &g_p_bmt_ctx_table->apps_bin[idx];

        printer_print_string("\nApplication binary information ");
        printer_print_int((int32_t)idx, PRINTER_BASE_DECIMAL);
        printer_print_string(":\n");

        printer_print_string("    Application binary ID:            ");
        printer_print_int((int32_t)idx, PRINTER_BASE_DECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application entry point:          0x");
        printer_print_int((int32_t)p_app_bin->entry_point, PRINTER_BASE_HEXADECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application load address:         0x");
        printer_print_int((int32_t)p_app_bin->load_address, PRINTER_BASE_HEXADECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application segments count:       ");
        printer_print_int((int32_t)p_app_bin->segments_count, PRINTER_BASE_DECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application compatibility status: ");
        printer_print_string(p_app_bin->is_compatible ? "Compatible" : "Incompatible");
        printer_print_string("\n");

        printer_print_string("    Application stack top:            0x");
        printer_print_int((int32_t)p_app_bin->memory_info.stack_top, PRINTER_BASE_HEXADECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application stack size:           ");
        printer_print_int((int32_t)p_app_bin->memory_info.stack_size, PRINTER_BASE_HEXADECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application heap start:           0x");
        printer_print_int((int32_t)p_app_bin->memory_info.heap_start, PRINTER_BASE_HEXADECIMAL);
        printer_print_string("\n");

        printer_print_string("    Application heap size:            ");
        printer_print_int((int32_t)p_app_bin->memory_info.heap_size, PRINTER_BASE_HEXADECIMAL);

        printer_print_string("\n\n");
    }

    printer_print_string("\n");
}
