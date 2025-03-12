#include "elf_krn.h"
#include "elf_check.h"
#include "elf_build.h"

bool_t elf_check_is_segment_metadata(const addr_t elf_addr, const uint32_t segment_idx)
{
    const ELF64_elf_hdr_t *p_elf_header      = (const ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *p_segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + segment_idx * p_elf_header->segm_hdr_ent_size);

    /* Metadata magic is found at the physical address of the segment start */
    return (*(addr_t *)(p_segment_hdr->phy_addr) == K_ELF_CHECK_METADATA_MAGIC);
}
