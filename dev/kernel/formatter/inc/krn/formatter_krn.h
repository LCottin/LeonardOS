#ifndef __FORMATTER_KRN_H__
#define __FORMATTER_KRN_H__

#include "types_usr.h"
#include "stream_krn.h"

/**********************************************************************
 * @brief Format the provided string.
 *
 * @param stream Stream for handling arguments.
 * @param format String to print before being formatted.
 * @param args Arguments to format.
 *
 * @return None.
 **********************************************************************/
extern void formatter_parse(stream_t *stream, const char_t *format, va_list args);


#endif /* __FORMATTER_KRN_H__ */
