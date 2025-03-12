#include "elf_krn.h"
#include "elf_build.h"
#include "elf_build_prv.h"

void elf_build_segment_info(const addr_t elf_addr, ELF64_binary_info_t *p_bin_info)
{
    const ELF64_elf_hdr_t *elf_header = (const ELF64_elf_hdr_t *)elf_addr;

    p_bin_info->segments_count = elf_info_get_nb_segments(elf_addr);

    for (uint32_t idx = 0; idx < p_bin_info->segments_count; idx++)
    {
        const ELF64_segment_hdr_t *segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + elf_header->segm_hdr_off + idx * elf_header->segm_hdr_ent_size);
        const bool_t is_segment_metadata       = elf_check_is_segment_metadata(elf_addr, idx);

        p_bin_info->segments[idx].hdr_addr    = (addr_t)segment_hdr;
        p_bin_info->segments[idx].virt_addr   = segment_hdr->virt_addr;
        p_bin_info->segments[idx].phy_addr    = segment_hdr->phy_addr;
        p_bin_info->segments[idx].flags       = segment_hdr->flags;
        p_bin_info->segments[idx].type        = segment_hdr->type;
        p_bin_info->segments[idx].mem_size    = (size_t)segment_hdr->mem_size;
        p_bin_info->segments[idx].file_size   = (size_t)segment_hdr->file_size;
        p_bin_info->segments[idx].file_offset = segment_hdr->offset;

        if (is_segment_metadata == TRUE)
        {
            /* Read metadata information */
            elf_build_meta_info(elf_addr, idx, &p_bin_info->memory_info, &p_bin_info->type);
        }
        else
        {
            /* This segment is not metadata, nothing more to do */
        }
    }
}
