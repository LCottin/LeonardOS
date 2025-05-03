#include "bmt_ctx.h"
#include "bmt_krn.h"
#include "printer_krn.h"
#include "strings_utils_usr.h"

void bmt_info_print_table(void)
{
    /* Print the binary information */
    printer_print_string("    Number of ELF binaries: ");
    printer_print_int((int32_t)g_p_bmt_ctx_table->binaries_count, PRINTER_BASE_DECIMAL);
    printer_print_string("\n");

    /* Loop through all the binaries in the bmt table */
    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->binaries_count; idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_ctx_table->binaries[idx];

        printer_print_string("    Binary type:            ");
        printer_print_int((int32_t)p_binary->type, PRINTER_BASE_DECIMAL);
        printer_print_string("\n");

        printer_print_string("    Entry point:            ");
        printer_print_address(p_binary->entry_point);
        printer_print_string("\n");

        printer_print_string("    Load address:           ");
        printer_print_address(p_binary->load_address);
        printer_print_string("\n");

        printer_print_string("    Segments count:         ");
        printer_print_int((int32_t)p_binary->segments_count, PRINTER_BASE_DECIMAL);
        printer_print_string("\n");

        printer_print_string("    Compatibility status:   ");
        printer_print_string(p_binary->is_compatible ? "Compatible\n" : "Incompatible\n");
        printer_print_string("\n");

        /* Loop through all the segments in the binary */
        for (uint32_t seg_idx = 0; seg_idx < p_binary->segments_count; seg_idx++)
        {
            const ELF64_custom_segment_t *p_segment = &p_binary->segments[seg_idx];

            printer_print_string("\t Segment header address: ");
            printer_print_address(p_segment->hdr_addr);
            printer_print_string("\n");

            printer_print_string("\t Segment type:           ");
            printer_print_int((int32_t)p_segment->type, PRINTER_BASE_DECIMAL);
            printer_print_string("\n");

            printer_print_string("\t Physical address:       ");
            printer_print_address(p_segment->phy_addr);
            printer_print_string("\n");

            printer_print_string("\t Virtual address:        ");
            printer_print_address(p_segment->virt_addr);
            printer_print_string("\n");

            printer_print_string("\t File size:              ");
            printer_print_int((int32_t)p_segment->file_size, PRINTER_BASE_DECIMAL);
            printer_print_string("\n");

            printer_print_string("\t Memory size:            ");
            printer_print_int((int32_t)p_segment->mem_size, PRINTER_BASE_DECIMAL);
            printer_print_string("\n");

            printer_print_string("\t Flags:                  ");
            printer_print_int((int32_t)p_segment->flags, PRINTER_BASE_DECIMAL);
            printer_print_string("\n\n");
        }
    }
}
