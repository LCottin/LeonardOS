#include "elf_build.h"
#include "elf_info.h"

uint32_t elf_info_get_nb_segments(const ELF64_elf_hdr_t *p_elf_header)
{
    return p_elf_header->segm_hdr_nb_entry;
}
