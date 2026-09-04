#ifndef __ELF_BUILD_PRV_H__
#define __ELF_BUILD_PRV_H__

#include "elf_krn.h"
#include "elf_build.h"

/**********************************************************************
 * @brief Fills metadata and memory information associated to the binary.
 *
 * @param p_segment_hdr The address of the elf header in memory.
 * @param p_metadata_info Pointer to the metadata information structure to fill.
 * @param p_memory_info Pointer to the memory information structure to fill.
 * @return None.
 **********************************************************************/
extern void elf_build_meta_info(
    const ELF64_segment_hdr_t *p_segment_hdr,
    metadata_t                *p_metadata_info,
    metadata_memory_info_t    *p_memory_info);


#endif /* __ELF_BUILD_PRV_H__ */
