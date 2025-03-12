#include "elf_krn.h"
#include "elf_check.h"
#include "elf_build.h"

bool_t elf_check_match_magic(const addr_t elf_addr)
{
    const ELF64_elf_hdr_t *p_header = (const ELF64_elf_hdr_t *)elf_addr;
    const uint32_t magic            = *(const uint32_t *)p_header->ident;

    return (magic == K_ELF_CHECK_MAGIC);
}
