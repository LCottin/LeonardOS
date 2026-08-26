#ifndef __ELF_CHECK_H__
#define __ELF_CHECK_H__

#include "types_usr.h"
#include "elf_build.h"

/**********************************************************************
 * @brief Checks if a segment is a metadata segment.
 *
 * This function checks if a segment is a metadata segment by reading the first
 * 64-bit word of the segment and comparing it to a known magic number.
 *
 * @param segment_hdr The address of the segment header.
 * @return bool_t Returns TRUE if the segment is a metadata segment, FALSE otherwise.
 **********************************************************************/
bool_t elf_check_is_segment_metadata(const ELF64_segment_hdr_t * segment_hdr);


#endif /* __ELF_CHECK_H__ */
