#include "elf_krn.h"
#include "elf_build.h"

ELF64_file_type_t elf_build_convert_magic_to_type(const ELF64_file_magic_t elf_magic)
{
    ELF64_file_type_t elf_type;

    switch (elf_magic)
    {
        case ELF_FILE_BOOT_MAGIC:
        {
            elf_type = ELF64_FILE_BOOT;
            break;
        }
        case ELF_FILE_KERNEL_MAGIC:
        {
            elf_type = ELF64_FILE_KERNEL;
            break;
        }
        case ELF_FILE_USER_MAGIC:
        {
            elf_type = ELF64_FILE_USER;
            break;
        }
        default:
        {
            elf_type = ELF64_FILE_UNKNOWN;
            break;
        }
    }

    return elf_type;
}
