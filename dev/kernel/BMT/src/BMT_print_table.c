#include "BMT.h"
#include "boot_prv.h"
#include "string_utils.h"
#include "memory_ops.h"

void BMT_print_table(void)
{
    /* Loop through all the binaries in the BMT table */
    for (uint32_t idx = 0; idx < g_p_bmt_table->binaries_count; idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_table->binaries[idx];
        char str[32];

        /* Print the binary information */
        boot_print("Number of ELF binaries: ");
        boot_print(string_utils_itoa(g_p_bmt_table->binaries_count, str, 16));
        memory_ops_set(str, 0, 32);
        boot_print("\n");

        boot_print("Binary type: ");
        boot_print(string_utils_itoa(p_binary->type, str, 16));
        memory_ops_set(str, 0, 32);
        boot_print("\n");

        boot_print("Entry point: ");
        boot_print(string_utils_itoa(p_binary->entry_point, str, 16));
        memory_ops_set(str, 0, 32);
        boot_print("\n");

        boot_print("Load address: ");
        boot_print(string_utils_itoa(p_binary->load_address, str, 16));
        memory_ops_set(str, 0, 32);
        boot_print("\n");

        boot_print("Segments count: ");
        boot_print(string_utils_itoa(p_binary->segments_count, str, 16));
        memory_ops_set(str, 0, 32);
        boot_print("\n");

        boot_print("Compatibility status: ");
        boot_print(p_binary->is_compatible ? "Compatible\n\n" : "Incompatible\n\n");
        boot_print("\n");

        /* Loop through all the segments in the binary */
        for (uint32_t seg_idx = 0; seg_idx < p_binary->segments_count; seg_idx++)
        {
            const ELF64_custom_segment_t *p_segment = &p_binary->segments[seg_idx];

            boot_print("Segment header address: ");
            boot_print(string_utils_itoa(p_segment->hdr_addr, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("Segment type: ");
            boot_print(string_utils_itoa(p_segment->type, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("Physical address: ");
            boot_print(string_utils_itoa(p_segment->phy_addr, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("Virtual address: ");
            boot_print(string_utils_itoa(p_segment->virt_addr, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("File size: ");
            boot_print(string_utils_itoa(p_segment->file_size, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("Memory size: ");
            boot_print(string_utils_itoa(p_segment->mem_size, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("Flags: ");
            boot_print(string_utils_itoa(p_segment->flags, str, 16));
            memory_ops_set(str, 0, 32);
            boot_print("\n");

            boot_print("\n");
        }
    }
}
