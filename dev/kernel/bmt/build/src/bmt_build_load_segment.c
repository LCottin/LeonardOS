#include "bmt_build_prv.h"
#include "memory_ops_usr.h"

void bmt_build_load_segment(const addr_t bin_load_addr, const ELF64_custom_segment_t *p_segment)
{
    const addr_t src_addr = bin_load_addr + p_segment->file_offset;
    addr_t dst_addr       = p_segment->virt_addr;

    /* Copy the segment to the correct memory location */
    if ((p_segment->file_size > 0)  && (src_addr != dst_addr))
    {
        memory_ops_copy((ptr_t)dst_addr, (cptr_t)src_addr, p_segment->file_size);
    }
    else
    {
        /* Nothing to copy for this segment, nothing more to do */
    }

    /* Zero out the remaining memory if the memory size is larger than the file size */
    if (p_segment->mem_size > p_segment->file_size)
    {
        memory_ops_set((ptr_t)(dst_addr + p_segment->file_size), 0, p_segment->mem_size - p_segment->file_size);
    }
    else
    {
        /* Nothing to zero out for this segment, nothing more to do */
    }
}
