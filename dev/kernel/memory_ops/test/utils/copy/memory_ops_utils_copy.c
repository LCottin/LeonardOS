#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "memory_ops_usr.h"

/* ================================================================== */
/* Test group 1: memcpy behaviour                                       */
/* ================================================================== */

static       char_t  s_dst[64];
static const char_t *s_src = "LeonardOS";

static void setup_memcpy(void)
{
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_memcpy(void)
{
    memory_ops_utils_copy(s_dst, s_src, 10);
}

static bool_t check_memcpy(void)
{
    return spec_utils_memcmp(s_dst, s_src, 10) == 0 ? TRUE: FALSE;
}

/* ================================================================== */
/* Test table                                                           */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    { "memcpy copies bytes correctly", setup_memcpy, run_memcpy, check_memcpy},
};

/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(
            "memory_ops_utils_copy",
            s_cases,
            sizeof(s_cases) / sizeof(s_cases[0]));

    while(1);
}
