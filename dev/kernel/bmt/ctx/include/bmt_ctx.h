#ifndef __BMT_CTX_H__
#define __BMT_CTX_H__

#include "types_usr.h"
#include "ELF.h"

/**********************************************************************
 * @brief Maximum number of ELF binaries in the bmt table.
 **********************************************************************/
#define K_BMT_CTX_MAX_ELF_BINARIES 5U


/***********************************************************************
 * @brief Structure to hold the bmt table.
 **********************************************************************/
typedef struct
{
    ELF64_binary_info_t binaries[K_BMT_CTX_MAX_ELF_BINARIES];   /* ELF binary data */
    uint32_t            binaries_count;                         /* Number of ELF binaries */
    uint8_t             padding[4];                             /* Padding */
} bmt_ctx_table_t;


/**********************************************************************
 * @brief Global pointer to the bmt table.
 **********************************************************************/
extern bmt_ctx_table_t *g_p_bmt_ctx_table;


#endif /* __BMT_CTX_H__ */
