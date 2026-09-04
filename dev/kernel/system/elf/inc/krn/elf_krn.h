#ifndef __ELF_KRN_H__
#define __ELF_KRN_H__

#include "types_usr.h"
#include "metadata_usr.h"

/**********************************************************************
 * @brief Maximum number of segments in an ELF file.
 **********************************************************************/
#define K_ELF_MAX_SEGMENTS 10U


/**********************************************************************
 * @brief Segment type for LOAD segments.
 **********************************************************************/
#define K_ELF_PT_LOAD            1U       /* Program header type: LOAD */


/**********************************************************************
 * @brief Structure to hold custom information about an ELF segment.
 **********************************************************************/
typedef struct
{
    addr_t   hdr_addr;                        /* Segment header address */
    addr_t   virt_addr;                       /* Virtual address */
    addr_t   phy_addr;                        /* Physical address */
    addr_t   file_offset;                     /* Offset in file */
    uint32_t type;                            /* Segment type */
    size_t   mem_size;                        /* Size in memory */
    size_t   file_size;                       /* Size in file */
    uint8_t  padding[4];                      /* Padding */
} ELF64_custom_segment_t;




/**********************************************************************
 * @brief Structure to hold information about an ELF binary.
 **********************************************************************/
typedef struct
{
    metadata_t              metadata;                           /* Binary metadata */
    uint32_t                segments_count;                     /* Number of loadable segments */
    bool_t                  is_compatible;                      /* Compatibility status */
    addr_t                  entry_point;                        /* Entry point address */
    addr_t                  load_address;                       /* Physical load address */
    ELF64_custom_segment_t  segments[K_ELF_MAX_SEGMENTS];       /* Segment information */
    metadata_memory_info_t  memory_info;                        /* Memory information */
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
 * @brief Retrieves the load type of an ELF binary.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return ELF64_file_type_t The type of the ELF binary.
 **********************************************************************/
metadata_binary_type_t elf_info_get_type(const addr_t elf_addr);


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
 * @brief Fills a binary structure with information from an ELF.
 *
 * This function extracts information from an ELF segment header and fills a custom
 * segment structure with the relevant data.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @param p_bin_info Pointer to the binary information structure to fill.
 * @return None.
 **********************************************************************/
void elf_build_binary_info(const addr_t elf_addr, ELF64_binary_info_t *p_bin_info);


#endif /* __ELF_KRN_H__ */
