#ifndef __CONSOLE_KRN_H__
#define __CONSOLE_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Initializes console and ring buffer.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void console_ctx_init(void);


/**********************************************************************
 * @brief Pushes a character into the console ring buffer.
 *
 * @param c Character to push.
 * @return None.
 **********************************************************************/
extern void console_buffer_push(const char_t c);


/**********************************************************************
 * @brief Pops a character from the console ring buffer.
 *
 * @param None.
 * @return The next character from the ring buffer.
 **********************************************************************/
extern char_t console_buffer_pop(void);


/**********************************************************************
 * @brief Checks whether the console ring buffer is empty.
 *
 * @param None.
 * @return true if the ring buffer is empty, false otherwise.
 **********************************************************************/
extern bool_t console_buffer_is_empty(void);


#endif /* __CONSOLE_KRN_H__ */
