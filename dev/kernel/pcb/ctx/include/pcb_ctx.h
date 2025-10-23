#ifndef __PCB_CTX_H__
#define __PCB_CTX_H__

#include "types_usr.h"

#include "pcb_krn.h"
#include "pcb_state.h"
#include "pcb_ident.h"
#include "pcb_control.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Structure of PCB context for one process.
 **********************************************************************/
typedef struct
{
    pcb_state_registers_t registers;    /* PCB registers */
    pcb_ident_t           ident;        /* PCB identifier */
    pcb_states_t          state;        /* PCB state */
    pcb_control_t         control;      /* PCB control */
    uint8_t               padding[268]; /* Padding */
} pcb_ctx_bin_t;


/**********************************************************************
 * @brief Structure of PCB context for all processes.
 **********************************************************************/
typedef struct
{
    pcb_ctx_bin_t  pcb_krn_ctx;                             /* PCB kernel context */
    pcb_ctx_bin_t  pcb_apps_ctx[K_BMT_MAX_APP_BINARIES];    /* PCB applications contexts */
    uint32_t       pcb_apps_count;                          /* Number of PCB application contexts */
    uint8_t        padding[4];                              /* Padding */
} pcb_ctx_table_t;


/**********************************************************************
 * @brief Global structure to store the PCB context for all processes.
 **********************************************************************/
extern pcb_ctx_table_t g_pcb_ctx_table;

extern void pcb_ctx_save_addr(void);

#endif /* __PCB_CTX_H__ */
