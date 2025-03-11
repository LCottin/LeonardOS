#include "elf_krn.h"
#include "elf_build.h"

addr_t elf_get_entry_point(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;

    return p_header->entry_point;
}

uint32_t elf_get_nb_segments(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;

    return p_header->segm_hdr_nb_entry;
}

