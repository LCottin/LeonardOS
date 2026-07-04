#ifndef __PRINTER_STREAM_PRV_H__
#define __PRINTER_STREAM_PRV_H__

#include "stream_krn.h"

/**********************************************************************
 * @brief Print a byte.
 *
 * @param value The byte to be printed.
 * @param stream The stream to print the byte to.
 *
 * @return None.
 **********************************************************************/
extern void printer_stream_print_byte(const byte_t c, stream_t *stream);


/**********************************************************************
 * @brief Stream associated to string formatting
 **********************************************************************/
extern stream_t printer_stream;


#endif /* __PRINTER_STREAM_PRV_H__ */
