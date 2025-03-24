#include "bmt_ctx.h"
#include "bmt_krn.h"
#include "serial_krn.h"
#include "strings_utils_usr.h"
#include "memory_ops_usr.h"

void bmt_info_print_table(void)
{
    /* Loop through all the binaries in the bmt table */
    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->binaries_count; idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_ctx_table->binaries[idx];
        char str[32];

        /* Print the binary information */
        serial_print_string("    Number of ELF binaries: ");
        serial_print_string(string_utils_itoa((int32_t)g_p_bmt_ctx_table->binaries_count, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Binary type:            ");
        serial_print_string(string_utils_itoa((int32_t)p_binary->type, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Entry point:            0x");
        serial_print_string(string_utils_itoa((int32_t)p_binary->entry_point, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Load address:           0x");
        serial_print_string(string_utils_itoa((int32_t)p_binary->load_address, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Segments count:         ");
        serial_print_string(string_utils_itoa((int32_t)p_binary->segments_count, str, 16));
        memory_ops_set(str, 0, 32);
        serial_print_string("\n");

        serial_print_string("    Compatibility status:   ");
        serial_print_string(p_binary->is_compatible ? "Compatible\n" : "Incompatible\n");
        serial_print_string("\n");

        /* Loop through all the segments in the binary */
        for (uint32_t seg_idx = 0; seg_idx < p_binary->segments_count; seg_idx++)
        {
            const ELF64_custom_segment_t *p_segment = &p_binary->segments[seg_idx];

            serial_print_string("\t Segment header address: 0x");
            serial_print_string(string_utils_itoa((int32_t)p_segment->hdr_addr, str, 16));
            memory_ops_set(str, 0, 32);
            serial_print_string("\n");

            serial_print_string("\t Segment type:           ");
            serial_print_string(string_utils_itoa((int32_t)p_segment->type, str, 16));
            memory_ops_set(str, 0, 32);
            serial_print_string("\n");

            serial_print_string("\t Physical address:       0x");
            serial_print_string(string_utils_itoa((int32_t)p_segment->phy_addr, str, 16));
            memory_ops_set(str, 0, 32);
            serial_print_string("\n");

            serial_print_string("\t Virtual address:        0x");
            serial_print_string(string_utils_itoa((int32_t)p_segment->virt_addr, str, 16));
            memory_ops_set(str, 0, 32);
            serial_print_string("\n");

            serial_print_string("\t File size:              ");
            serial_print_string(string_utils_itoa((int32_t)p_segment->file_size, str, 16));
            memory_ops_set(str, 0, 32);
            serial_print_string("\n");

            serial_print_string("\t Memory size:            ");
            serial_print_string(string_utils_itoa((int32_t)p_segment->mem_size, str, 16));
            memory_ops_set(str, 0, 32);
            serial_print_string("\n");
        }
    }
}
