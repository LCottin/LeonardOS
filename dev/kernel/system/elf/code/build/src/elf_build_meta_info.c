#include "elf_krn.h"
#include "elf_build.h"
#include "elf_build_prv.h"
#include "elf_check.h"
#include "metadata_usr.h"
#include "memory_ops_usr.h"

void elf_build_meta_info(
    const ELF64_segment_hdr_t *p_segment_hdr,
    metadata_t                *p_metadata_info,
    metadata_memory_info_t    *p_memory_info)
{
    /* Read metadata information */
    memory_ops_utils_copy(p_metadata_info, (cptr_t)p_segment_hdr->phy_addr, sizeof(metadata_t));

    /* Read memory information */
    const metadata_memory_data_t *p_memory_data = (const metadata_memory_data_t *)(p_segment_hdr->phy_addr + sizeof(metadata_t));

    for (uint32_t idx = 0; idx < K_ELF_METADATA_NB_ENTRIES; idx++)
    {
        switch (p_memory_data[idx].tag)
        {
            case K_ELF_METADATA_STACK_TOP:
            {
                p_memory_info->stack_top = (addr_t)p_memory_data[idx].data;
                break;
            }

            case K_ELF_METADATA_STACK_SIZE:
            {
                p_memory_info->stack_size = (size_t)p_memory_data[idx].data;
                break;
            }

            case K_ELF_METADATA_HEAP_START:
            {
                p_memory_info->heap_start = (addr_t)p_memory_data[idx].data;
                break;
            }

            case K_ELF_METADATA_HEAP_SIZE:
            {
                p_memory_info->heap_size = (size_t)p_memory_data[idx].data;
                break;
            }

            default:
                break;
        }
    }
}
