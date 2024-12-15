#ifndef __MEMORY_OPS_H__
#define __MEMORY_OPS_H__

#include "types.h"

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
extern ptr_t memory_ops_copy(ptr_t dest, cptr_t src, const size_t size);

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
extern ptr_t memory_ops_set(ptr_t dest, const int32_t value, const size_t size);

/**
 * @brief Compares two memory areas byte by byte.
 *
 * This function compares the first 'size' bytes of the memory areas pointed to by 'src1' and 'src2'.
 *
 * @param src1 Pointer to the first memory area to be compared.
 * @param src2 Pointer to the second memory area to be compared.
 * @param size Number of bytes to compare.
 *
 * @return A value indicating the result of the comparison:
 *         - 0 if the contents of both memory areas are equal
 *         - A negative value if the first differing byte in src1 is less than the corresponding byte in src2
 *         - A positive value if the first differing byte in src1 is greater than the corresponding byte in src2
 */
extern int32_t memory_ops_cmp(cptr_t src1, cptr_t src2, const size_t size);

#endif /* __MEMORY_OPS_H__ */
