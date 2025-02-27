#include "BMT.h"
#include "BMT_prv.h"
#include "memory_ops.h"

void BMT_init(void)
{
    g_p_bmt_table = (BMT_table_t *)&__bmt_start;
    memory_ops_set(g_p_bmt_table, 0, sizeof(BMT_table_t));
}
