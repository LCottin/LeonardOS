#ifndef __BMT_KRN_H__
#define __BMT_KRN_H__

#include "types_usr.h"
#include "elf_krn.h"

/**********************************************************************
 * @brief Maximum number of APP binaries in the bmt table.
 **********************************************************************/
#define K_BMT_MAX_APP_BINARIES 5U


/***********************************************************************
 * @brief Structure to hold the bmt table.
 **********************************************************************/
typedef struct
{
    ELF64_binary_info_t krn_bin;                                /* ELF kernel binary data */
    ELF64_binary_info_t apps_bin[K_BMT_MAX_APP_BINARIES];       /* ELF app binary data */
    uint32_t            apps_count;                             /* Number of ELF app binaries */
    uint8_t             padding[4];                             /* Padding */
} bmt_ctx_table_t;


/**********************************************************************
 * @brief Adds an ELF binary to the bmt table.
 *
 * @param elf_addr The address of the ELF binary.
 * @return None.
 **********************************************************************/
extern void bmt_build_add_elf(const addr_t elf_addr);


/**********************************************************************
 * @brief Builds the bmt table from the ELF binaries.
 *
 * @return None.
 **********************************************************************/
extern void bmt_build_table(void);


/**********************************************************************
 * @brief Copies the ELF binaries to memory.
 *
 * @return None.
 **********************************************************************/
extern void bmt_build_copy_binaries(void);


/**********************************************************************
 * @brief Prints the bmt table.
 *
 * @return None.
 **********************************************************************/
extern void bmt_info_print_table(void);


/**********************************************************************
 * @brief Retrieves the kernel entry point address.
 *
 * @return The kernel entry point address.
 **********************************************************************/
extern addr_t bmt_info_get_kernel_entry(void);


/**********************************************************************
 * @brief Retrieves the kernel stack top address.
 *
 * @return The kernel stack top address.
 **********************************************************************/
extern addr_t bmt_info_get_kernel_stack_top(void);


/**********************************************************************
 * @brief Retrieves the app entry point address.
 *
 * @param app_id The app identifier.
 * @return The app entry point address.
 **********************************************************************/
extern addr_t bmt_info_get_app_entry(const uint32_t app_id);


/**********************************************************************
 * @brief Retrieves the app stack top address.
 *
 * @param app_id The app identifier.
 * @return The app stack top address.
 **********************************************************************/
extern addr_t bmt_info_get_app_stack_top(const uint32_t app_id);


/**********************************************************************
 * @brief Initializes the bmt context.
 *
 * @return None.
 **********************************************************************/
extern void bmt_ctx_init(void);


#endif /* __BMT_KRN_H__ */
