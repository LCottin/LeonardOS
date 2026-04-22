#ifndef __MMIO_KRN_H__
#define __MMIO_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Writes a 32-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 32-bit value to write to the specified MMIO address.
 * @return None.
 **********************************************************************/
extern void mmio_io32_write(ptr_t addr, const uint32_t value);


/**********************************************************************
 * @brief Reads a 32-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 32-bit access.
 * @return The 32-bit value read from the specified MMIO address.
 **********************************************************************/
extern uint32_t mmio_io32_read(cptr_t addr);


/**********************************************************************
 * @brief Sets a specific bit in an 32-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io32_set_bit(ptr_t addr, const uint32_t bit);


/**********************************************************************
 * @brief Clears a specific bit in an 32-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io32_clear_bit(ptr_t addr, const uint32_t bit);


/**********************************************************************
 * @brief Toggles a specific bit in an 32-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io32_toggle_bit(ptr_t addr, const uint32_t bit);


#endif /* __MMIO_IO32_KRN_H__ */
