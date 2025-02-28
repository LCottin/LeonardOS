#ifndef __MMIO_IO16_H__
#define __MMIO_IO16_H__

#include "types.h"

/**
 * @brief Writes a 16-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 16-bit value to write to the specified MMIO address.
 * @return None.
 */
extern void mmio_io16_write(ptr_t addr, const uint16_t value);

/**
 * @brief Reads a 16-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 16-bit access.
 * @return The 16-bit value read from the specified MMIO address.
 */
extern uint16_t mmio_io16_read(cptr_t addr);

/**
 * @brief Sets a specific bit in an 16-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 */
extern void mmio_io16_set_bit(ptr_t addr, const uint16_t bit);

/**
 * @brief Clears a specific bit in an 16-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 */
extern void mmio_io16_clear_bit(ptr_t addr, const uint16_t bit);

/**
 * @brief Toggles a specific bit in an 16-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 */
extern void mmio_io16_toggle_bit(ptr_t addr, const uint16_t bit);

#endif /* __MMIO_IO16_H__ */
