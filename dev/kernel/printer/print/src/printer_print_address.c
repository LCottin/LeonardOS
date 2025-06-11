#include "printer_krn.h"
#include "uart_krn.h"
#include "strings_utils_usr.h"

void printer_print_address(const addr_t value)
{
    char_t buffer_low[16];
    char_t buffer_high[16];

    const int32_t value_low  = (int32_t)(value & 0xFFFFFFFFU);
    const int32_t value_high = (int32_t)((value >> 32U) & 0xFFFFFFFFU);

    string_utils_itoa(value_low,  buffer_low,  16U);
    string_utils_itoa(value_high, buffer_high, 16U);

    printer_print_string("0x");
    printer_print_string(buffer_high);
    printer_print_string(buffer_low);
}
