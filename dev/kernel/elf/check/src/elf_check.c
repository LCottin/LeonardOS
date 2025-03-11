#include "elf_krn.h"
#include "elf_check.h"
#include "elf_check_prv.h"
#include "elf_build.h"

bool_t elf_match_magic(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;
    const uint32_t magic            = *(const uint32_t *)p_header->ident;

    return (magic == K_ELF_MAGIC);
}

bool_t elf_is_compatible(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;
    bool_t is_compatible            = TRUE;

    is_compatible &= (p_header->type    == K_ELF_TYPE_EXEC);
    is_compatible &= (p_header->machine == K_ELF_MACHINE_AARCH64);

    is_compatible &= (p_header->elhdr_size                        == sizeof(ELF64_elf_hdr_t));
    is_compatible &= (p_header->ident[K_ELF_IDENT_CLASS_OFF]      == K_ELF_IDENT_CLASS_VAL);
    is_compatible &= (p_header->ident[K_ELF_IDENT_DATA_OFF]       == K_ELF_IDENT_DATA_VAL);
    is_compatible &= (p_header->ident[K_ELF_IDENT_VERSION_OFF]    == K_ELF_IDENT_VERSION_VAL);
    is_compatible &= (p_header->ident[K_ELF_IDENT_OSABI_OFF]      == K_ELF_IDENT_OSABI_VAL);
    is_compatible &= (p_header->ident[K_ELF_IDENT_ABIVERSION_OFF] == K_ELF_IDENT_ABIVERSION_VAL);

    return is_compatible;
}

bool_t elf_is_segment_metadata(const addr_t elf_addr, const uint32_t segment_idx)
{
    const ELF64_elf_hdr_t *p_elf_header      = (const ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *p_segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + segment_idx * p_elf_header->segm_hdr_ent_size);

    /* Metadata magic is found at the physical address of the segment start */
    return (*(addr_t *)(p_segment_hdr->phy_addr) == K_ELF_METADATA_MAGIC);
}
