#ifndef __MMIO_IO8_H__
#define __MMIO_IO8_H__

#include "types.h"

/**
 * @brief Writes a 8-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 8-bit value to write to the specified MMIO address.
 * @return None.
 */
extern void mmio_io8_write(cptr_t addr, const uint8_t value);

/**
 * @brief Reads a 8-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 8-bit access.
 * @return The 8-bit value read from the specified MMIO address.
 */
extern uint8_t mmio_io8_read(cptr_t addr);

/**
 * @brief Sets a specific bit in an 8-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 */
extern void mmio_io8_set_bit(cptr_t addr, const uint8_t bit);

/**
 * @brief Clears a specific bit in an 8-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 */
extern void mmio_io8_clear_bit(cptr_t addr, const uint8_t bit);

/**
 * @brief Toggles a specific bit in an 8-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 */
extern void mmio_io8_toggle_bit(cptr_t addr, const uint8_t bit);

#endif /* __MMIO_IO8_H__ */
