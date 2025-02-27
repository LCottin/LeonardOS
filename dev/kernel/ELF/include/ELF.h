#ifndef __ELF_H__
#define __ELF_H__

#include "types.h"

/**
 * @brief Maximum number of segments in an ELF file.
 */
#define K_ELF_MAX_SEGMENTS 10U

/**
 * @brief Segment type for LOAD segments.
 */
#define K_ELF_PT_LOAD            1U       /* Program header type: LOAD */

/**
 * @brief ELF file types.
 */
typedef enum
{
    ELF_TYPE_NONE   = 0,      /* No file type */
    ELF_FILE_BOOT   = 1,      /* Boot file */
    ELF_FILE_KERNEL = 2,      /* Kernel file */
    ELF_FILE_USER   = 3,      /* User file */
    ELF_FILE_MAX
} ELF_file_type_t;

/**
 * @brief Structure to hold custom information about an ELF segment.
 */
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


/**
 * @brief Structure to hold information about an ELF binary.
 */
typedef struct
{
    ELF64_file_type_t       type;                               /* Binary type */
    addr_t                  entry_point;                        /* Entry point address */
    addr_t                  load_address;                       /* Physical load address */
    ELF64_custom_segment_t  segments[K_ELF_MAX_SEGMENTS];       /* Segment information */
    uint32_t                segments_count;                     /* Number of loadable segments */
    bool_t                  is_compatible;                      /* Compatibility status */
    ELF64_memory_info_t     memory_info;                        /* Memory information */
} ELF64_binary_info_t;

/**
 * @brief Validates an ELF header to ensure it's a valid ELF file.
 *
 * This function checks the ELF header for correct magic number
 * to determine if the file is a valid ELF executable.
 *
 * @param elf_addr The address of the ELF header in memory.
 * @return bool_t Returns TRUE if the ELF header is valid, FALSE otherwise.
 */
bool_t elf_match_magic(const addr_t elf_addr);

/**
 * @brief Retrieves the entry point of an ELF binary.
 *
 * This function reads the entry point address from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return addr_t The entry point address of the ELF binary.
 */
addr_t elf_get_entry_point(const addr_t elf_addr);

/**
 * @brief Checks if an ELF binary is compatible with the system.
 *
 * This function checks the ELF binary for compatibility with the system.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return bool_t Returns TRUE if the ELF binary is compatible, FALSE otherwise.
 */
bool_t elf_is_compatible(const addr_t elf_addr);

/**
 * @brief Retrieves the size of an ELF binary.
 *
 * This function reads the size of the ELF binary from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return size_t The size of the ELF binary.
 */
size_t elf_get_size(const addr_t elf_addr);

/**
 * @brief Retrieves the number of segments in an ELF binary.
 *
 * This function reads the number of segments from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return uint32_t The number of segments in the ELF binary.
 */
uint32_t elf_get_nb_segments(const addr_t elf_addr);

/**
 * @brief Fills a custom segment structure with information from an ELF segment.
 *
 * This function extracts information from an ELF segment header and fills a custom
 * segment structure with the relevant data.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @param segment_data Pointer to the custom segment structure to fill.
 * @param segment_idx The index of the segment to extract information from.
 * @return None.
 */
void elf_fill_segment_info(const addr_t elf_addr, ELF64_custom_segment_t *segment_data, const uint32_t segment_idx);

/**
 * @brief Retrieves the type of an ELF binary.
 *
 * This function reads the type of the ELF binary from the ELF header.
 *
 * @param elf_addr The address of the ELF binary in memory.
 * @return ELF_file_type_t The type of the ELF binary.
 */
ELF_file_type_t elf_get_type(const addr_t elf_addr);

#endif /* __ELF_H__ */
