#include "bmt_ctx.h"
#include "bmt_krn.h"
#include "serial_krn.h"
#include "strings_utils_usr.h"
#include "memory_ops_usr.h"

void bmt_info_print_table(void)
{
    char str[32];

    /* Print the kernel binary information */
    serial_print_string("Kernel binary information:\n");
    serial_print_string("    Entry point:                 0x");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.entry_point, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    serial_print_string("    Kernel load address:         0x");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.load_address, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    serial_print_string("    Kernel segments count:       ");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.segments_count, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    serial_print_string("    Kernel compatibility status: ");
    serial_print_string(g_p_bmt_ctx_table->krn_bin.is_compatible ? "Compatible\n" : "Incompatible\n");

    serial_print_string("    Kernel stack top:            0x");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.stack_top, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    serial_print_string("    Kernel stack size:           ");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.stack_size, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    serial_print_string("    Kernel heap start:           0x");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.heap_start, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    serial_print_string("    Kernel heap size:            ");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->krn_bin.memory_info.heap_size, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n\n");

    serial_print_string("App binary information:\n");
    serial_print_string("    App binary count: ");
    serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->apps_count, str, 16));
    memory_ops_set(str, 0, 32);
    serial_print_string("\n");

    /* Loop through all the applications in the bmt table */
    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->apps_count; idx++)
    {
        const ELF64_binary_info_t *p_app_bin = &g_p_bmt_ctx_table->apps_bin[idx];

        serial_print_string("\nApplication binary information ");
        serial_print_string(string_utils_itoa((int32_t)idx, str, 10));
        memory_ops_set(str, 0, 32);
        serial_print_string(":\n");
        serial_print_string("    Application binary ID:            ");
        serial_print_string(string_utils_itoa((int32_t)idx, str, 10));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application entry point:          0x");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->entry_point, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application load address:         0x");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->load_address, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application segments count:       ");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->segments_count, str, 10));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application compatibility status: ");
        serial_print_string(p_app_bin->is_compatible ? "Compatible" : "Incompatible");
        serial_print_string("\n");

        serial_print_string("    Application stack top:            0x");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->memory_info.stack_top, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application stack size:           ");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->memory_info.stack_size, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application heap start:           0x");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->memory_info.heap_start, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Application heap size:            ");
        serial_print_string(string_utils_itoa((int32_t)p_app_bin->memory_info.heap_size, str, 16));
        memory_ops_set(str, 0, 32);

        serial_print_string("\n\n");
    }

    serial_print_string("\n");
}
