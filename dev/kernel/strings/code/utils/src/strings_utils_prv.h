#ifndef __STRINGS_UTILS_PRV_H__
#define __STRINGS_UTILS_PRV_H__

#include "types_usr.h"
#include "printer_usr.h"

/**********************************************************************
 * @brief Get the size of the prefix according to the requested base.
 *
 * @param base The base to use for the prefix.
 * @param prefix_buf Buffer to store the prefix.
 *
 * @return The size of the prefix.
 **********************************************************************/
extern size_t strings_utils_get_base_prefix(const printer_base_t base, char_t *prefix_buf);


/**********************************************************************
 * @brief Convert an unsigned 64-bit integer to a string representation in the specified base
 *
 * @param base The base to use for the prefix.
 * @param value The unsigned 64-bit integer to convert.
 * @param str Buffer to store the string representation.
 * @return The size of the string representation.
 *
 * @note The buffer must be large enough to hold the resulting string representation.
 **********************************************************************/
extern size_t strings_utils_utoa_raw(const printer_base_t base, const uint64_t value, char_t *str);


#endif /* __STRINGS_UTILS_PRV_H__ */
