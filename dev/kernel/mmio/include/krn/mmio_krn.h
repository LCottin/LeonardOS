#ifndef __MMIO_KRN_H__
#define __MMIO_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Writes a 8-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 8-bit value to write to the specified MMIO address.
 * @return None.
 **********************************************************************/
extern void mmio_io8_write(ptr_t addr, const uint8_t value);


/**********************************************************************
 * @brief Reads a 8-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 8-bit access.
 * @return The 8-bit value read from the specified MMIO address.
 **********************************************************************/
extern uint8_t mmio_io8_read(cptr_t addr);


/**********************************************************************
 * @brief Sets a specific bit in an 8-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io8_set_bit(ptr_t addr, const uint8_t bit);


/**********************************************************************
 * @brief Clears a specific bit in an 8-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io8_clear_bit(ptr_t addr, const uint8_t bit);


/**********************************************************************
 * @brief Toggles a specific bit in an 8-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io8_toggle_bit(ptr_t addr, const uint8_t bit);



/***********************************************************************
 * @brief Writes a 16-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 16-bit value to write to the specified MMIO address.
 * @return None.
 **********************************************************************/
extern void mmio_io16_write(ptr_t addr, const uint16_t value);


/***********************************************************************
 * @brief Reads a 16-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 16-bit access.
 * @return The 16-bit value read from the specified MMIO address.
 **********************************************************************/
extern uint16_t mmio_io16_read(cptr_t addr);


/***********************************************************************
 * @brief Sets a specific bit in an 16-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io16_set_bit(ptr_t addr, const uint16_t bit);


/***********************************************************************
 * @brief Clears a specific bit in an 16-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io16_clear_bit(ptr_t addr, const uint16_t bit);


/***********************************************************************
 * @brief Toggles a specific bit in an 16-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io16_toggle_bit(ptr_t addr, const uint16_t bit);


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


/**********************************************************************
 * @brief Writes a 64-bit value to a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to write a single byte to a specified MMIO address.
 *
 * @param addr The MMIO address to write to.
 * @param value The 64-bit value to write to the specified MMIO address.
 * @return None.
 **********************************************************************/
extern void mmio_io64_write(ptr_t addr, const uint64_t value);


/**********************************************************************
 * @brief Reads a 64-bit value from a specified memory-mapped I/O (MMIO) address.
 *
 * This function is used to read a single byte from a specified MMIO address.
 *
 * @param addr The MMIO address to read from. This address must be properly aligned for 64-bit access.
 * @return The 64-bit value read from the specified MMIO address.
 **********************************************************************/
extern uint64_t mmio_io64_read(cptr_t addr);


/**********************************************************************
 * @brief Sets a specific bit in an 64-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to set.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io64_set_bit(ptr_t addr, const uint64_t bit);


/**********************************************************************
 * @brief Clears a specific bit in an 64-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to clear.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io64_clear_bit(ptr_t addr, const uint64_t bit);


/**********************************************************************
 * @brief Toggles a specific bit in an 64-bit memory-mapped I/O register.
 *
 * @param addr The memory address of the I/O register.
 * @param bit The bit position (0-7) to toggle.
 *
 * @return This function does not return a value.
 **********************************************************************/
extern void mmio_io64_toggle_bit(ptr_t addr, const uint64_t bit);


#endif /* __MMIO_KRN_H__ */
