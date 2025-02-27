#include "ELF.h"
#include "ELF_prv.h"
#include "memory_ops.h"
#include "string_ops.h"

#define K_ELF_MAGIC             0x464C457FU             /* "\x7FELF" in little-endian */
#define K_ELF_METADATA_MAGIC    0x415441444154454DULL   /* "METADATA" */

#define K_ELF_IDENT_CLASS_OFF       4U       /* ELF Class */
#define K_ELF_IDENT_DATA_OFF        5U       /* Data Encoding */
#define K_ELF_IDENT_VERSION_OFF     6U       /* ELF Version */
#define K_ELF_IDENT_OSABI_OFF       7U       /* OS/ABI */
#define K_ELF_IDENT_ABIVERSION_OFF  8U       /* ABI Version */

#define K_ELF_IDENT_CLASS_VAL       2U       /* 64-bit ELF */
#define K_ELF_IDENT_DATA_VAL        1U       /* Little-endian */
#define K_ELF_IDENT_VERSION_VAL     1U       /* Current ELF version */
#define K_ELF_IDENT_OSABI_VAL       0U       /* System V ABI */
#define K_ELF_IDENT_ABIVERSION_VAL  0U       /* ABI Version */

#define K_ELF_MACHINE_AARCH64 183U           /* ARM64 */
#define K_ELF_TYPE_EXEC         2U           /* Executable file */

bool_t elf_match_magic(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;
    const uint32_t magic          = *(const uint32_t *)p_header->ident;

    return (magic == K_ELF_MAGIC);
}

addr_t elf_get_entry_point(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;

    return p_header->entry_point;
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

uint32_t elf_get_nb_segments(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;

    return p_header->segm_hdr_nb_entry;
}

void elf_fill_segment_info(const addr_t elf_addr, ELF64_binary_info_t *p_bin_info)
{
    const ELF64_elf_hdr_t *elf_header = (const ELF64_elf_hdr_t *)elf_addr;

    p_bin_info->segments_count = elf_get_nb_segments(elf_addr);

    for (uint32_t idx = 0; idx < p_bin_info->segments_count; idx++)
    {
        const ELF64_segment_hdr_t *segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + elf_header->segm_hdr_off + idx * elf_header->segm_hdr_ent_size);
        const bool_t is_segment_metadata       = elf_is_segment_metadata(elf_addr, idx);

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
            elf_fill_meta_info(elf_addr, idx, &p_bin_info->memory_info, &p_bin_info->type);
        }
        else
        {
            /* This segment is not metadata, nothing more to do */
        }
    }
}

bool_t elf_is_segment_metadata(const addr_t elf_addr, const uint32_t segment_idx)
{
    const ELF64_elf_hdr_t *p_elf_header      = (const ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *p_segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + segment_idx * p_elf_header->segm_hdr_ent_size);

    /* Metadata magic is found at the physical address of the segment start */
    return (*(addr_t *)(p_segment_hdr->phy_addr) == K_ELF_METADATA_MAGIC);
}

void elf_fill_meta_info(const addr_t elf_addr, const uint32_t segment_idx, ELF64_memory_info_t *p_memory_info, ELF64_file_type_t *p_elf_type)
{
    const ELF64_elf_hdr_t *p_elf_header      = (const ELF64_elf_hdr_t *)elf_addr;
    const ELF64_segment_hdr_t *p_segment_hdr = (const ELF64_segment_hdr_t *)(elf_addr + p_elf_header->segm_hdr_off + segment_idx * p_elf_header->segm_hdr_ent_size);

    /* Read ELF type, skip metadata magic number */
    const uint32_t elf_type_magic = *(const uint32_t *)(p_segment_hdr->phy_addr + sizeof(K_ELF_METADATA_MAGIC));

    if (elf_type_magic == ELF_FILE_BOOT_MAGIC)
    {
        *p_elf_type = ELF64_FILE_BOOT;
    }
    else if (elf_type_magic == ELF_FILE_KERNEL_MAGIC)
    {
        *p_elf_type = ELF64_FILE_KERNEL;
    }
    else if (elf_type_magic == ELF_FILE_USER_MAGIC)
    {
        *p_elf_type = ELF64_FILE_USER;
    }
    else
    {
        *p_elf_type = ELF64_FILE_UNKNOWN;
    }

    /* Read metadata information */
    const ELF64_metadata_t *p_metadata = (const ELF64_metadata_t *)(p_segment_hdr->phy_addr + sizeof(K_ELF_METADATA_MAGIC) + sizeof(ELF64_file_magic_t));

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
