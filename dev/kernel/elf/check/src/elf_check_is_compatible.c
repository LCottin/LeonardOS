#include "elf_krn.h"
#include "elf_check_prv.h"
#include "elf_build.h"

bool_t elf_check_is_compatible(const addr_t elf_addr)
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
