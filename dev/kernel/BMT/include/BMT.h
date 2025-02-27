#ifndef __BMT_H__
#define __BMT_H__

#include "types.h"
#include "ELF.h"

/**
 * @brief Maximum number of ELF binaries in the BMT table.
 */
#define K_BMT_MAX_ELF_BINARIES 5U

/**
 * @brief Structure to hold the BMT table.
 */
typedef struct
{
    ELF64_binary_info_t binaries[K_BMT_MAX_ELF_BINARIES];    /* ELF binary data */
    uint32_t            binaries_count;                      /* Number of ELF binaries */
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
