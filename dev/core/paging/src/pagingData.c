#include "pagingPrv.h"

page_table_t l1_table __attribute__((aligned(PAGE_SIZE)));
page_table_t l2_table __attribute__((aligned(PAGE_SIZE)));
page_table_t l3_table __attribute__((aligned(PAGE_SIZE)));
