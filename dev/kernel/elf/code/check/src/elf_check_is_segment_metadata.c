#include "elf_krn.h"
#include "elf_check.h"
#include "elf_build.h"
#include "metadata_usr.h"

bool_t elf_check_is_segment_metadata(const ELF64_segment_hdr_t * segment_hdr)
{
    /* Metadata magic is found at the physical address of the segment start */
    return (*(addr_t *)(segment_hdr->phy_addr) == K_METADATA_MAGIC);
}
