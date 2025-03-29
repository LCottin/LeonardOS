#ifndef __ELF_BUILD_PRV_H__
#define __ELF_BUILD_PRV_H__

/**********************************************************************
 * @brief Metadata tags for ELF segments.
 **********************************************************************/
typedef enum
{
    K_ELF_METADATA_STACK_TOP   = 1, /* Stack start address */
    K_ELF_METADATA_STACK_SIZE  = 2, /* Stack stop address */
    K_ELF_METADATA_HEAP_START  = 3, /* Heap start address */
    K_ELF_METADATA_HEAP_SIZE   = 4, /* Heap stop address */
    K_ELF_METADATA_NB_ENTRIES
} ELF64_metadata_tag_t;


/**********************************************************************
 * @brief Metadata structure for 64-bit ELF files.
 *
 * This structure represents a metadata entry in a 64-bit ELF file, containing
 * a tag and data pair.
 **********************************************************************/
typedef struct
{
    ELF64_metadata_tag_t tag;   /* Metadata tag */
    uint32_t            data;   /* Metadata data */
} ELF64_metadata_t;


/**********************************************************************
 * @brief Fills a memory information structure with metadata from an ELF segment.
 *
 * This function reads metadata from an ELF segment and fills a memory information
 * structure with the relevant data.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @param segment_idx The index of the segment to extract metadata from.
 * @param p_memory_info Pointer to the memory information structure to fill.
 * @param p_elf_type Pointer to the ELF file type to fill.
 * @return None.
 **********************************************************************/
void elf_build_meta_info(const addr_t elf_addr, const uint32_t segment_idx, ELF64_memory_info_t *p_memory_info, ELF64_file_type_t *p_elf_type);


#endif /* __ELF_BUILD_PRV_H__ */
