#ifndef __MMIO_IO64_H__
#define __MMIO_IO64_H__

#include "types.h"

/**
 * @brief Writes a 64-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 64-bit value to write to the specified MMIO address.
 * @return None.
 */
extern void mmio_io64_write(cptr_t addr, const uint64_t value);

/**
 * @brief Reads a 64-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 64-bit access.
 * @return The 64-bit value read from the specified MMIO address.
 */
extern uint64_t mmio_io64_read(cptr_t addr);

/**
 * @brief Sets a specific bit in an 64-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 */
extern void mmio_io64_set_bit(cptr_t addr, const uint64_t bit);

/**
 * @brief Clears a specific bit in an 64-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 */
extern void mmio_io64_clear_bit(cptr_t addr, const uint64_t bit);

/**
 * @brief Toggles a specific bit in an 64-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 */
extern void mmio_io64_toggle_bit(cptr_t addr, const uint64_t bit);

#endif /* __MMIO_IO64_H__ */
