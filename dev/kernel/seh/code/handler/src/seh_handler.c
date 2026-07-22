#include "seh_handler_prv.h"
#include "printer_krn.h"

static const char_t *g_seh_exception_messages[SEH_EXCEPTION_NB] =
{
    [SEH_EXCEPTION_FIQ]  = "FIQ exception",
    [SEH_EXCEPTION_IRQ]  = "IRQ exception",
    [SEH_EXCEPTION_SERR] = "SError exception",
};

void seh_handler(const reg_t reg_lr, const reg_t reg_esr, const seh_exception_type_t exception_type)
{
    printer_print_string("\r\n\n=======================================\r\nException occurred:");
    printer_print_formatted("\r\n\tException type:              %s", g_seh_exception_messages[exception_type]);
    printer_print_formatted("\r\n\tReturn address expected:     %x", reg_lr);
    printer_print_formatted("\r\n\tException Syndrome Register: %x", reg_esr);

    // seh_handler_decode_esr(reg_esr);

    printer_print_string("\r\n\n\tGoing to infinite loop ...\r\n");
    while(1)
    {
        ;
    }
}
