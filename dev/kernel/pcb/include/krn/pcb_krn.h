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
 * @param bmt_start_addr The start address of the BMT table.
 * @return bool_t Returns TRUE if the initialization was successful, FALSE otherwise.
 **********************************************************************/
extern bool_t pcb_init(const addr_t bmt_start_addr);


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
 * @brief Update the PCB context of the current and next tasks.
 *
 * @param current_task The ID of the current task.
 * @param next_task The ID of the next task.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_app_update(const uint32_t current_task, const uint32_t next_task);


/**********************************************************************
 * @brief Save the application context.
 *
 * @param task_id The ID of the task to save the context for.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_app_save(const uint32_t task_id);


/**********************************************************************
 * @brief Restore the application context.
 *
 * @param task_id The ID of the task to restore the context for.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_app_restore(const uint32_t task_id);


/**********************************************************************
 * @brief Save the kernel context.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_krn_save(void);


/**********************************************************************
 * @brief Restore the kernel context.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void pcb_ctx_krn_restore(void);


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


#endif /* __PCB_KRN_H__ */
