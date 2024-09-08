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
 * @return Pointer to the destination memory area.
 */
extern void *memcpy(void *dest, const void *src, const int size);

/**
 * @brief Fills the memory block pointed to by 'dest' with the specified 'value'.
 *
 * The function sets the first 'size' bytes of the memory block pointed to by 'dest' to the specified 'value'.
 * The function does not check for any overlapping areas between the source and destination memory blocks.
 * If the source and destination memory blocks overlap, the behavior of this function is undefined.
 *
 * @param dest Pointer to the destination memory area where the content is to be filled.
 * @param value The value to be set in the memory block. The value is passed as an integer, but it will be interpreted as unsigned char.
 * @param size Number of bytes to be filled with the specified 'value'.
 *
 * @return Pointer to the destination memory area.
 */
extern void *memset(void *dest, const int value, const int size);

#endif /* __MEMORY_H__ */
