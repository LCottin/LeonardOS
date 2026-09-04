#include "elf_krn.h"
#include "elf_build.h"

addr_t elf_info_get_entry_point(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;

    return p_header->entry_point;
}
