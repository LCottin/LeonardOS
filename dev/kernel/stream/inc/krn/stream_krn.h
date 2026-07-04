#ifndef __STREAM_KRN_H__
#define __STREAM_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Stream structure to provide to formatter
 **********************************************************************/
typedef struct stream_t
{
    void (*write_byte)(const byte_t byte, struct stream_t *stream);     /* Function pointer to handle byte */
    void (*reset)(struct stream_t *stream);                             /* Function pointer to reset stream */
    ptr_t context;                                                      /* Associated context */
} stream_t;


#endif /* __STREAM_KRN_H__ */
