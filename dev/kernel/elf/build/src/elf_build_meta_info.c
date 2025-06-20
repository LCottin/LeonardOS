#include "elf_krn.h"
#include "elf_build.h"
#include "elf_build_prv.h"
#include "elf_check.h"

void elf_build_meta_info(const addr_t elf_addr, const uint32_t segment_idx, ELF64_memory_info_t *p_memory_info, ELF64_file_type_t *p_elf_type)
{
    /* Extract ELF header and segment header */
    const ELF64_elf_hdr_t *p_elf_header      = (const ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *p_segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + segment_idx * p_elf_header->segm_hdr_ent_size);

    /* Read ELF type, skip metadata magic number */
    const uint32_t elf_type_magic = *(const uint32_t *)(p_segment_hdr->phy_addr + sizeof(K_ELF_CHECK_METADATA_MAGIC));
    *p_elf_type                   = elf_build_convert_magic_to_type(elf_type_magic);

    /* Read metadata information */
    const ELF64_metadata_t *p_metadata = (const ELF64_metadata_t *)(p_segment_hdr->phy_addr + sizeof(K_ELF_CHECK_METADATA_MAGIC) + sizeof(ELF64_file_magic_t));

    for (uint32_t idx = 0; idx < K_ELF_METADATA_NB_ENTRIES; idx++)
    {
        switch (p_metadata[idx].tag)
        {
            case K_ELF_METADATA_STACK_TOP:
            {
                p_memory_info->stack_top = p_metadata[idx].data;
                break;
            }
            case K_ELF_METADATA_STACK_SIZE:
            {
                p_memory_info->stack_size = p_metadata[idx].data;
                break;
            }
            case K_ELF_METADATA_HEAP_START:
            {
                p_memory_info->heap_start = p_metadata[idx].data;
                break;
            }
            case K_ELF_METADATA_HEAP_SIZE:
            {
                p_memory_info->heap_size = p_metadata[idx].data;
                break;
            }
            default:
                break;
        }
    }
}
