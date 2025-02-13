#include "BMT.h"

addr_t BMT_get_kernel_entry(void)
{
    /* TODO: compute kernel entry address from bmt table by parsing binaries */
    return g_p_bmt_table->binaries[0].entry_point;
}
