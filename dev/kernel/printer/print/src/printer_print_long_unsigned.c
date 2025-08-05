#include "printer_krn.h"
#include "strings_utils_usr.h"

void printer_print_long_unsigned(const uint64_t value, const printer_base_t base)
{
    char_t buffer[32];

    strings_utils_utoa(base, value, buffer);
    printer_print_string(buffer);
}
