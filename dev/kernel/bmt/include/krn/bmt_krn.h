#ifndef __BMT_KRN_H__
#define __BMT_KRN_H__

#include "types.h"
#include "ELF.h"

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
 * @brief Initializes the bmt context.
 *
 * @return None.
 **********************************************************************/
extern void bmt_ctx_init(void);


#endif /* __BMT_KRN_H__ */
