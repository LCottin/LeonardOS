#ifndef __ELF_KRN_H__
#define __ELF_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Maximum number of segments in an ELF file.
 **********************************************************************/
#define K_ELF_MAX_SEGMENTS 10U


/**********************************************************************
 * @brief Segment type for LOAD segments.
 **********************************************************************/
#define K_ELF_PT_LOAD            1U       /* Program header type: LOAD */


/**********************************************************************
 * @brief ELF file types.
 **********************************************************************/
typedef enum
{
    ELF64_FILE_UNKNOWN = 0,      /* No file type */
    ELF64_FILE_BOOT    = 1,      /* Boot file */
    ELF64_FILE_KERNEL  = 2,      /* Kernel file */
    ELF64_FILE_USER    = 3,      /* User file */
    ELF64_FILE_MAX
} ELF64_file_type_t;


/**********************************************************************
 * @brief Structure to hold custom information about an ELF segment.
 **********************************************************************/
typedef struct
{
    addr_t   hdr_addr;                        /* Segment header address */
    addr_t   virt_addr;                       /* Virtual address */
    addr_t   phy_addr;                        /* Physical address */
    uint32_t flags;                           /* Segment permissions (R, W, X) */
    uint32_t type;                            /* Segment type */
    size_t   mem_size;                        /* Size in memory */
    size_t   file_size;                       /* Size in file */
    addr_t   file_offset;                     /* Offset in file */
} ELF64_custom_segment_t;


/**********************************************************************
 * @brief Structure to hold memory information about a binary.
 **********************************************************************/
typedef struct
{
    addr_t stack_top;                         /* Stack top address */
    addr_t heap_start;                        /* Heap start address */
    size_t stack_size;                        /* Stack size */
    size_t heap_size;                         /* Heap size */
} ELF64_memory_info_t;


/**********************************************************************
 * @brief Structure to hold information about an ELF binary.
 **********************************************************************/
typedef struct
{
    ELF64_file_type_t       type;                               /* Binary type */
    uint32_t                segments_count;                     /* Number of loadable segments */
    addr_t                  entry_point;                        /* Entry point address */
    addr_t                  load_address;                       /* Physical load address */
    ELF64_custom_segment_t  segments[K_ELF_MAX_SEGMENTS];       /* Segment information */
    ELF64_memory_info_t     memory_info;                        /* Memory information */
    bool_t                  is_compatible;                      /* Compatibility status */
    uint8_t                 padding[4];                         /* Padding */
} ELF64_binary_info_t;


/**********************************************************************
 * @brief Validates an ELF header to ensure it's a valid ELF file.
 *
 * This function checks the ELF header for correct magic number
 * to determine if the file is a valid ELF executable.
 *
 * @param elf_addr The address of the ELF header in memory.
 * @return bool_t Returns TRUE if the ELF header is valid, FALSE otherwise.
 **********************************************************************/
bool_t elf_check_match_magic(const addr_t elf_addr);


/**********************************************************************
 * @brief Retrieves the entry point of an ELF binary.
 *
 * This function reads the entry point address from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return addr_t The entry point address of the ELF binary.
 **********************************************************************/
addr_t elf_info_get_entry_point(const addr_t elf_addr);


/**********************************************************************
 * @brief Checks if an ELF binary is compatible with the system.
 *
 * This function checks the ELF binary for compatibility with the system.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return bool_t Returns TRUE if the ELF binary is compatible, FALSE otherwise.
 **********************************************************************/
bool_t elf_check_is_compatible(const addr_t elf_addr);


/**********************************************************************
 * @brief Retrieves the number of segments in an ELF binary.
 *
 * This function reads the number of segments from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return uint32_t The number of segments in the ELF binary.
 **********************************************************************/
uint32_t elf_info_get_nb_segments(const addr_t elf_addr);


/**********************************************************************
 * @brief Fills a custom segment structure with information from an ELF segment.
 *
 * This function extracts information from an ELF segment header and fills a custom
 * segment structure with the relevant data.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @param p_bin_info Pointer to the binary information structure to fill.
 * @return None.
 **********************************************************************/
void elf_build_segment_info(const addr_t elf_addr, ELF64_binary_info_t *p_bin_info);


/**********************************************************************
 * @brief Checks if a segment is a metadata segment.
 *
 * This function checks if a segment is a metadata segment by reading the first
 * 64-bit word of the segment and comparing it to a known magic number.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @param segment_idx The index of the segment to check.
 * @return bool_t Returns TRUE if the segment is a metadata segment, FALSE otherwise.
 **********************************************************************/
bool_t elf_check_is_segment_metadata(const addr_t elf_addr, const uint32_t segment_idx);


#endif /* __ELF_KRN_H__ */
