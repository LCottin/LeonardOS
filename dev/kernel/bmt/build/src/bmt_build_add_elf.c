#include "bmt_krn.h"
#include "bmt_ctx.h"
#include "bmt_build_prv.h"
#include "elf_krn.h"

void bmt_build_add_elf(const addr_t elf_addr)
{
    /* Get the ELF type */
    ELF64_file_type_t elf_type = elf_info_get_type(elf_addr);

    switch (elf_type)
    {
        /* Add kernel ELF */
        case ELF64_FILE_KERNEL:
        {
            bmt_build_add_krn_elf(elf_addr);
            break;
        }

        /* Add user ELF */
        case ELF64_FILE_USER:
        {
            bmt_build_add_app_elf(elf_addr);
            break;
        }

        /* Other types of ELF are considered invalid */
        default:
        {
            /* Nothing to do */
            break;
        }
    }
}
