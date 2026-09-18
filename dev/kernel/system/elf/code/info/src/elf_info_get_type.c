#include "elf_krn.h"
#include "elf_check.h"
#include "elf_build.h"
#include "metadata_usr.h"
#include "elf_info.h"

metadata_binary_type_t elf_info_get_type(const addr_t elf_addr)
{
    bool_t                   is_segment_metadata;
    metadata_binary_type_t   elf_type;
    ELF64_segment_hdr_t     *p_segment_hdr;

    const ELF64_elf_hdr_t *p_elf_header = (const ELF64_elf_hdr_t *)elf_addr;
    const uint32_t segments_count       = elf_info_get_nb_segments(p_elf_header);
    uint32_t idx                        = 0;

    do
    {
        p_segment_hdr = (ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + idx * p_elf_header->segm_hdr_ent_size);

        /* Check if the segment is metadata */
        is_segment_metadata = elf_check_is_segment_metadata(p_segment_hdr);

        idx++;
    } while ((is_segment_metadata == FALSE) && (idx < segments_count));

    if (is_segment_metadata == TRUE)
    {
        /* Read ELF type, skip metadata magic number */
        const metadata_header_t *p_metadata_info = (const metadata_header_t *)p_segment_hdr->phy_addr;
        elf_type = p_metadata_info->type;
    }
    else
    {
        /* No metadata segment found, nothing more to do */
        elf_type = METADATA_TYPE_UNKNOWN;
    }

    return elf_type;
}
