#ifndef __MEMORY_STREAM_PRV_H__
#define __MEMORY_STREAM_PRV_H__

#include "types_usr.h"
#include "stream_krn.h"

/**********************************************************************
 * @brief Define the size of the memory stream buffer.
 **********************************************************************/
#define MEMORY_STREAM_BUFFER_SIZE 256


/**********************************************************************
 * @brief Structure to hold the context of the memory stream.
 **********************************************************************/
typedef struct
{
    byte_t buffer[MEMORY_STREAM_BUFFER_SIZE]; /* Buffer to hold the stream data */
    size_t length;                            /* Current length of the data in the buffer */
} memory_stream_context_t;


/**********************************************************************
 * @brief Writes a byte to the memory stream.
 *
 * This function writes a single byte to the memory stream.
 *
 * @param byte The byte to write to the stream.
 * @param stream Pointer to the stream_t structure.
 * @return None.
 **********************************************************************/
extern void memory_stream_write_byte(const byte_t byte, stream_t *stream);


/**********************************************************************
 * @brief Resets the memory stream.
 *
 * This function resets the memory stream, clearing its contents.
 *
 * @param stream Pointer to the stream_t structure.
 * @return None.
 **********************************************************************/
extern void memory_stream_reset(stream_t *stream);


/**********************************************************************
 * @brief Stream associated to memory formatting.
 **********************************************************************/
extern stream_t memory_stream;


#endif /* __MEMORY_STREAM_PRV_H__ */
