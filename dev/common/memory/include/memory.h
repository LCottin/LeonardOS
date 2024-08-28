#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Copies 'size' bytes from the memory area pointed to by 'src' to the memory area pointed to by 'dest'.
 *
 * The function does not check for any overlapping areas between the source and destination memory blocks.
 * If the source and destination memory blocks overlap, the behavior of this function is undefined.
 *
 * @param dest Pointer to the destination memory area where the content is to be copied.
 * @param src Pointer to the source memory area from where the content is to be copied.
 * @param size Number of bytes to be copied.
 *
 * @return None.
 */
extern void memcpy(void *dest, const void *src, const int size);

#endif