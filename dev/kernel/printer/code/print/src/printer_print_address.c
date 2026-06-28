#include "printer_krn.h"

void printer_print_address(const addr_t value)
{
    printer_print_long_unsigned(value, STRINGS_UTILS_BASE_HEXADECIMAL);
}
