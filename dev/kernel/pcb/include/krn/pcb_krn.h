#ifndef __PCB_KRN_H__
#define __PCB_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Enumeration of PCB states.
 **********************************************************************/
typedef enum
{
    PCB_STATE_NEW,              /* New PCB */
    PCB_STATE_READY,            /* Ready PCB */
    PCB_STATE_RUNNING,          /* Running PCB */
    PCB_STATE_BLOCKED,          /* Blocked PCB */
    PCB_STATE_SUSPENDED,        /* Suspended PCB */
    PCB_STATE_TERMINATED,       /* Terminated PCB */
    PCB_STATE_UNKNOWN           /* Unknown PCB */
} pcb_states_t;


/**********************************************************************
 * @brief Initialize the PCB module.
 *
 * @param None.
 **********************************************************************/
extern void pcb_init(void);


/**********************************************************************
 * @brief Get the number of PCB contexts.
 *
 * @return uint32_t The number of PCB contexts.
 **********************************************************************/
extern uint32_t pcb_ctx_get_count(void);


/**********************************************************************
 * @brief Set all the application processes to READY state.
 **********************************************************************/
extern void pcb_state_set_apps_ready(void);


/**********************************************************************
 * @brief Get the entry point of the application task.
 *
 * @param task_id The ID of the task to get the entry for.
 * @return addr_t The entry point address of the application task.
 **********************************************************************/
extern addr_t pcb_ctx_get_app_entry(const uint32_t task_id);


/**********************************************************************
 * @brief Get the state of the task.
 *
 * @param task_id The ID of the task to get the state for.
 * @return pcb_states_t The state of the task.
 **********************************************************************/
extern pcb_states_t pcb_state_get_state(const uint32_t task_id);


/**********************************************************************
 * @brief Get the current task conext.
 *
 * @param task_id The ID of the task to get the context for.
 * @return Task id current context address.
 **********************************************************************/
extern addr_t pcb_ctx_get_app_ctx(const uint32_t task_id);


/**********************************************************************
 * @brief Get the kernel context.
 *
 * @param None.
 * @return Kernel context address
 **********************************************************************/
extern addr_t pcb_ctx_get_krn_ctx(void);


#endif /* __PCB_KRN_H__ */
