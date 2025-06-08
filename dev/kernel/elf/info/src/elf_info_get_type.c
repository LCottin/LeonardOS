#include "elf_krn.h"
#include "elf_check.h"
#include "elf_build.h"

ELF64_file_type_t elf_info_get_type(const addr_t elf_addr)
{
    bool_t is_segment_metadata;
    ELF64_segment_hdr_t *p_segment_hdr;

    const ELF64_elf_hdr_t *p_elf_header = (const ELF64_elf_hdr_t *)elf_addr;
    const uint32_t segments_count       = elf_info_get_nb_segments(elf_addr);
    uint32_t idx                        = 0;
    uint32_t elf_magic                  = 0;

    do
    {
        p_segment_hdr = (ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + idx * p_elf_header->segm_hdr_ent_size);

        /* Check if the segment is metadata */
        is_segment_metadata = elf_check_is_segment_metadata(elf_addr, idx);

        idx++;
    } while ((is_segment_metadata == FALSE) && (idx < segments_count));

    if (is_segment_metadata == TRUE)
    {
        /* Read ELF type, skip metadata magic number */
        elf_magic = *(const uint32_t *)(p_segment_hdr->phy_addr + sizeof(K_ELF_CHECK_METADATA_MAGIC));
    }
    else
    {
        /* No metadata segment found, nothing more to do */
        elf_magic = 0;
    }

    const ELF64_file_type_t elf_type = elf_build_convert_magic_to_type(elf_magic);

    return elf_type;
}
