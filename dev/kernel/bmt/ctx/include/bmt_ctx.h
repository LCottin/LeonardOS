#ifndef __BMT_CTX_H__
#define __BMT_CTX_H__

#include "types_usr.h"
#include "elf_krn.h"
#include "bmt_krn.h"

/***********************************************************************
 * @brief Structure to hold the bmt table.
 **********************************************************************/
typedef struct
{
    ELF64_binary_info_t binaries[K_BMT_MAX_ELF_BINARIES];       /* ELF binary data */
    uint32_t            binaries_count;                         /* Number of ELF binaries */
    uint8_t             padding[4];                             /* Padding */
} bmt_ctx_table_t;


/**********************************************************************
 * @brief Global pointer to the bmt table.
 **********************************************************************/
extern bmt_ctx_table_t *g_p_bmt_ctx_table;


#endif /* __BMT_CTX_H__ */
