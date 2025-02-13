#include "ELF.h"
#include "ELF_prv.h"
#include "memory_ops.h"
#include "string_ops.h"

bool_t elf_match_magic(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *header = (ELF64_elf_hdr_t *)elf_addr;
    const uint32_t magic          = *(uint32_t *)header->ident;

    return (magic == K_ELF_MAGIC);
}

addr_t elf_get_entry_point(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *header = (ELF64_elf_hdr_t *)elf_addr;

    return header->entry_point;
}

bool_t elf_is_compatible(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *header = (ELF64_elf_hdr_t *)elf_addr;
    bool_t is_compatible          = TRUE;

    is_compatible &= (header->type    == K_ELF_TYPE_EXEC);
    is_compatible &= (header->machine == K_ELF_MACHINE_AARCH64);

    is_compatible &= (header->elhdr_size                        == sizeof(ELF64_elf_hdr_t));
    is_compatible &= (header->ident[K_ELF_IDENT_CLASS_OFF]      == K_ELF_IDENT_CLASS_VAL);
    is_compatible &= (header->ident[K_ELF_IDENT_DATA_OFF]       == K_ELF_IDENT_DATA_VAL);
    is_compatible &= (header->ident[K_ELF_IDENT_VERSION_OFF]    == K_ELF_IDENT_VERSION_VAL);
    is_compatible &= (header->ident[K_ELF_IDENT_OSABI_OFF]      == K_ELF_IDENT_OSABI_VAL);
    is_compatible &= (header->ident[K_ELF_IDENT_ABIVERSION_OFF] == K_ELF_IDENT_ABIVERSION_VAL);

    return is_compatible;
}

size_t elf_get_size(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *elf_header      = (ELF64_elf_hdr_t *)elf_addr;

    addr_t elf_max_end_segment_addr = 0;

    /* Find the maximum end address of all segments */
    for (uint32_t idx = 0; idx < elf_header->segm_hdr_nb_entry; idx++)
    {
        const ELF64_segment_hdr_t *segment_hdr = (ELF64_segment_hdr_t *)(elf_addr + elf_header->segm_hdr_off + idx * elf_header->segm_hdr_ent_size);
        const addr_t elf_end_segment_addr      = segment_hdr->virt_addr + segment_hdr->mem_size;

        if (elf_end_segment_addr > elf_max_end_segment_addr)
        {
            elf_max_end_segment_addr = elf_end_segment_addr;
        }
    }

    /* Return the size of the ELF binary */
    return (size_t)(elf_max_end_segment_addr - elf_addr);
}

uint32_t elf_get_nb_segments(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *header = (ELF64_elf_hdr_t *)elf_addr;

    return header->segm_hdr_nb_entry;
}

void elf_fill_segment_info(const addr_t elf_addr, ELF64_custom_segment_t *segment_data, const uint32_t segment_idx)
{
    const ELF64_elf_hdr_t *elf_header      = (ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *segment_hdr = (ELF64_segment_hdr_t *)(elf_addr + elf_header->segm_hdr_off + segment_idx * elf_header->segm_hdr_ent_size);

    segment_data->hdr_addr    = (addr_t)segment_hdr;
    segment_data->virt_addr   = segment_hdr->virt_addr;
    segment_data->phy_addr    = segment_hdr->phy_addr;
    segment_data->flags       = segment_hdr->flags;
    segment_data->type        = segment_hdr->type;
    segment_data->mem_size    = (size_t)segment_hdr->mem_size;
    segment_data->file_size   = (size_t)segment_hdr->file_size;
    segment_data->align       = segment_hdr->align;
    segment_data->file_offset = segment_hdr->offset;
}

ELF_file_type_t elf_get_type(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *elf_header      = (ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *segment_hdr = (ELF64_segment_hdr_t *)(elf_addr);

    /* TODO: Get the meta section to extract the type */

    return ELF_TYPE_NONE;
}
