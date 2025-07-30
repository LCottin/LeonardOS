#include "strings_utils_prv.h"

size_t strings_utils_get_base_prefix(const printer_base_t base, char_t *prefix_buf)
{
    size_t base_prefix_size;

    switch (base)
    {
        case PRINTER_BASE_BINARY:
            prefix_buf[0] = '0';
            prefix_buf[1] = 'b';
            base_prefix_size = 2U;
            break;

        case PRINTER_BASE_OCTAL:
            prefix_buf[0] = '0';
            prefix_buf[1] = '0';
            base_prefix_size = 2U;
            break;

        case PRINTER_BASE_HEXADECIMAL:
            prefix_buf[0] = '0';
            prefix_buf[1] = 'x';
            base_prefix_size = 2U;
            break;

        default:
            base_prefix_size = 0;
            break;
    }

    return base_prefix_size;
}
