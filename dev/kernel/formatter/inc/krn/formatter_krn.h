#ifndef __FORMATTER_KRN_H__
#define __FORMATTER_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Stream structure to provide to formatter
 **********************************************************************/
typedef struct
{
    void (*write_char)(const char c);       /* Function pointer to handle char */
    ptr_t context;                          /* Associated context */
} formatter_stream_t;


/**********************************************************************
 * @brief Format the provided string.
 *
 * @param stream Stream for handling arguments.
 * @param format String to print before being formatted.
 * @param args Arguments to format.
 *
 * @return None.
 **********************************************************************/
extern void formatter_parse(const formatter_stream_t *stream, const char_t *format, va_list args);


#endif /* __FORMATTER_KRN_H__ */
