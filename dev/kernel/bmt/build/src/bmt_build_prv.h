#ifndef __BMT_BUILD_PRV_H__
#define __BMT_BUILD_PRV_H__

#include "types_usr.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Adds an ELF binary to the bmt table.
 *
 * @param elf_addr The address of the ELF binary.
 * @return None.
 **********************************************************************/
extern void bmt_build_add_krn_elf(const addr_t elf_addr);


/**********************************************************************
 * @brief Adds an application ELF binary to the bmt table.
 *
 * @param elf_addr The address of the ELF binary.
 * @return TRUE if the ELF was added, FALSE otherwise.
 **********************************************************************/
extern bool_t bmt_build_add_app_elf(const addr_t elf_addr);


/**********************************************************************
 * @brief Copies the kernel and application binaries to their load addresses and
 * zeros the bss segments.
 *
 * @param bin_load_addr The load address of the binary.
 * @param p_segment The segment to copy.
 * @return None.
 **********************************************************************/
extern void bmt_build_load_segment(const addr_t bin_load_addr, const ELF64_custom_segment_t *p_segment);


#endif
