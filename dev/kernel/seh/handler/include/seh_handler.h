#ifndef __SEH_HANDLER_H__
#define __SEH_HANDLER_H__

/**********************************************************************
 * @brief Handler for irq interruption.
 *
 * @return None.
 **********************************************************************/
extern void seh_handler_irq(void);


/**********************************************************************
 * @brief Handler for fiq interruption.
 *
 * @return None.
 **********************************************************************/
extern void seh_handler_fiq(void);


/**********************************************************************
 * @brief Handler for sync interruption.
 *
 * @return None.
 **********************************************************************/
extern void seh_handler_sync(void);


/**********************************************************************
 * @brief Handler for serr interruption.
 *
 * @return None.
 **********************************************************************/
extern void seh_handler_serr(void);


#endif /* __SEH_HANDLER_H__ */
