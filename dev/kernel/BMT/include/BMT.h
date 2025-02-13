#ifndef __BMT_H__
#define __BMT_H__

#include "types.h"
#include "ELF.h"

/**
 * @brief Maximum number of ELF binaries in the BMT table.
 */
#define K_BMT_MAX_ELF_BINARIES 2U

/**
 * @brief Structure to hold information about an ELF binary.
 */
typedef struct
{
    char_t                 name[K_ELF_MAX_NAME_LEN];          /* Binary name or identifier */
    ELF_file_type_t        type;                              /* Binary type */
    addr_t                 entry_point;                       /* Entry point address */
    addr_t                 load_address;                      /* Physical load address */
    size_t                 binary_size;                       /* Total size in memory */
    ELF64_custom_segment_t segments[K_ELF_MAX_SEGMENTS];      /* Segment information */
    uint32_t               segments_count;                    /* Number of loadable segments */
    bool_t                 is_compatible;                     /* Compatibility status */
} BMT_binary_info_t;

/**
 * @brief Structure to hold the BMT table.
 */
typedef struct
{
    BMT_binary_info_t binaries[K_BMT_MAX_ELF_BINARIES];    /* ELF binary data */
    uint32_t          binaries_count;                      /* Number of ELF binaries */
} BMT_table_t;

/**
 * @brief Global pointer to the ELF table.
 */
extern BMT_table_t *g_p_bmt_table;

/**
 * @brief Adds an ELF binary to the BMT table.
 *
 * @param elf_addr The address of the ELF binary.
 * @return None.
 */
extern void BMT_add_elf(const addr_t elf_addr);

/**
 * @brief Builds the BMT table from the ELF binaries.
 *
 * @return None.
 */
extern void BMT_build_table(void);

/**
 * @brief Copies the ELF binaries to memory.
 *
 * @return None.
 */
extern void BMT_copy_binaries(void);

/**
 * @brief Prints the BMT table.
 *
 * @return None.
 */
extern void BMT_print_table(void);

/**
 * @brief Retrieves the kernel entry point address.
 *
 * @return The kernel entry point address.
 */
extern addr_t BMT_get_kernel_entry(void);

#endif /* __BMT_H__ */
