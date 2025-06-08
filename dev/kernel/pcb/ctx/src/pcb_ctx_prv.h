#ifndef __PCB_CTX_PRV_H__
#define __PCB_CTX_PRV_H__

#include "types_usr.h"
#include "pcb_state.h"

/**********************************************************************
 * @brief Save the context of any task.
 *
 * @param pcb_state_registers Pointer to the PCB state registers structure.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_save(pcb_state_registers_t *pcb_state_registers);


/**********************************************************************
 * @brief Restore the context of any task.
 *
 * @param pcb_state_registers Pointer to the PCB state registers structure.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_restore(const pcb_state_registers_t *pcb_state_registers);


#endif /* __PCB_CTX_PRV_H__ */
