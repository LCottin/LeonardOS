#ifndef __ELF_INFO_H__
#define __ELF_INFO_H__

#include "types_usr.h"
#include "elf_build.h"

/**********************************************************************
 * @brief Retrieves the number of segments in an ELF binary.
 *
 * This function reads the number of segments from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return uint32_t The number of segments in the ELF binary.
 **********************************************************************/
uint32_t elf_info_get_nb_segments(const ELF64_elf_hdr_t *p_elf_header);


#endif /* __ELF_INFO_H__ */
