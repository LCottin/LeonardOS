#ifndef __PCB_CTX_H__
#define __PCB_CTX_H__

#include "types_usr.h"

#include "pcb_state.h"
#include "pcb_ident.h"
#include "pcb_control.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Structure of PCB context for one process.
 **********************************************************************/
typedef struct
{
    pcb_ident_t           ident;        /* PCB identifier */
    pcb_states_t          state;        /* PCB state */
    pcb_control_t         control;      /* PCB control */
    uint8_t               padding[268]; /* Padding */
    pcb_state_registers_t registers;    /* PCB registers */
} pcb_ctx_t;


/**********************************************************************
 * @brief Structure of PCB context for all processes.
 **********************************************************************/
typedef struct
{
    pcb_ctx_t pcb_ctx[K_BMT_MAX_ELF_BINARIES];    /* PCB context */
} pcb_ctx_table_t;


/**********************************************************************
 * @brief Global structure to the PCB context for all processes.
 **********************************************************************/
extern pcb_ctx_table_t g_pcb_table_all;


#endif /* __PCB_CTX_H__ */
