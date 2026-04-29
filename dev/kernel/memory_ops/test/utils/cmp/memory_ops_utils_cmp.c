#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "memory_ops_usr.h"

/* ================================================================== */
/* Shared buffers                                                       */
/* ================================================================== */

#define BUFFER_SIZE 128U

static char_t s_buf1[BUFFER_SIZE];
static char_t s_buf2[BUFFER_SIZE];

static int32_t s_result;

/* ================================================================== */
/* Helper: fill a buffer with a known repeating byte pattern           */
/* ================================================================== */

static void fill_pattern(char_t *buf, const size_t size, const char_t start_val)
{
    size_t idx;

    for (idx = 0U; idx < size; idx++)
    {
        buf[idx] = (char_t)(start_val + (char_t)idx);
    }
}

/* ================================================================== */
/* Test group 1: equal memory areas                                    */
/* ================================================================== */

/* --- TC-CMP-001: identical buffers return 0 ----------------------- */

static void setup_tc001(void)
{
    fill_pattern(s_buf1, 16U, 0x10U);
    fill_pattern(s_buf2, 16U, 0x10U);
}

static void run_tc001(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 16U);
}

static bool_t check_tc001(void)
{
    return (s_result == 0) ? TRUE : FALSE;
}

/* --- TC-CMP-002: single equal byte returns 0 ---------------------- */

static void setup_tc002(void)
{
    s_buf1[0] = (char_t)0x42U;
    s_buf2[0] = (char_t)0x42U;
}

static void run_tc002(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc002(void)
{
    return (s_result == 0) ? TRUE : FALSE;
}

/* --- TC-CMP-003: zero-size compare always returns 0 --------------- */
/*     The loop never executes; length == size == 0, so result is 0  */

static void setup_tc003(void)
{
    s_buf1[0] = (char_t)0x01U;
    s_buf2[0] = (char_t)0xFFU;   /* bytes differ, but size is 0 */
}

static void run_tc003(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 0U);
}

static bool_t check_tc003(void)
{
    return (s_result == 0) ? TRUE : FALSE;
}

/* --- TC-CMP-004: all-zeros buffers return 0 ----------------------- */

static void setup_tc004(void)
{
    spec_utils_memset(s_buf1, 0x00U, 32U);
    spec_utils_memset(s_buf2, 0x00U, 32U);
}

static void run_tc004(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 32U);
}

static bool_t check_tc004(void)
{
    return (s_result == 0) ? TRUE : FALSE;
}

/* --- TC-CMP-005: all-0xFF buffers return 0 ------------------------ */

static void setup_tc005(void)
{
    spec_utils_memset(s_buf1, 0xFFU, 32U);
    spec_utils_memset(s_buf2, 0xFFU, 32U);
}

static void run_tc005(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 32U);
}

static bool_t check_tc005(void)
{
    return (s_result == 0) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test group 2: src1 < src2 (negative result)                        */
/* ================================================================== */

/* --- TC-CMP-006: first byte of src1 less than src2 ---------------- */

static void setup_tc006(void)
{
    s_buf1[0] = (char_t)0x10U;
    s_buf2[0] = (char_t)0x20U;
}

static void run_tc006(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc006(void)
{
    return (s_result < 0) ? TRUE : FALSE;
}

/* --- TC-CMP-007: difference at the last byte, src1 < src2 --------- */

static void setup_tc007(void)
{
    fill_pattern(s_buf1, 8U, 0x10U);
    fill_pattern(s_buf2, 8U, 0x10U);
    s_buf1[7] = (char_t)0x01U;
    s_buf2[7] = (char_t)0xFEU;
}

static void run_tc007(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 8U);
}

static bool_t check_tc007(void)
{
    return (s_result < 0) ? TRUE : FALSE;
}

/* --- TC-CMP-008: exact negative delta value ----------------------- */
/*     buf1[0]=0x10, buf2[0]=0x20  =>  result = 0x10 - 0x20 = -16   */

static void setup_tc008(void)
{
    s_buf1[0] = (char_t)0x10U;
    s_buf2[0] = (char_t)0x20U;
}

static void run_tc008(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc008(void)
{
    return (s_result == ((int32_t)0x10U - (int32_t)0x20U)) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test group 3: src1 > src2 (positive result)                        */
/* ================================================================== */

/* --- TC-CMP-009: first byte of src1 greater than src2 ------------- */

static void setup_tc009(void)
{
    s_buf1[0] = (char_t)0x80U;
    s_buf2[0] = (char_t)0x01U;
}

static void run_tc009(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc009(void)
{
    return (s_result > 0) ? TRUE : FALSE;
}

/* --- TC-CMP-010: difference at the last byte, src1 > src2 --------- */

static void setup_tc010(void)
{
    fill_pattern(s_buf1, 8U, 0x30U);
    fill_pattern(s_buf2, 8U, 0x30U);
    s_buf1[7] = (char_t)0xFEU;
    s_buf2[7] = (char_t)0x01U;
}

static void run_tc010(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 8U);
}

static bool_t check_tc010(void)
{
    return (s_result > 0) ? TRUE : FALSE;
}

/* --- TC-CMP-011: exact positive delta value ----------------------- */
/*     buf1[0]=0x30, buf2[0]=0x20  =>  result = 0x30 - 0x20 = 16    */

static void setup_tc011(void)
{
    s_buf1[0] = (char_t)0x30U;
    s_buf2[0] = (char_t)0x20U;
}

static void run_tc011(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc011(void)
{
    return (s_result == ((int32_t)0x30U - (int32_t)0x20U)) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test group 4: difference position                                   */
/* ================================================================== */

/* --- TC-CMP-012: difference at the very first byte ---------------- */

static void setup_tc012(void)
{
    fill_pattern(s_buf1, 16U, 0x40U);
    fill_pattern(s_buf2, 16U, 0x40U);
    s_buf1[0] = (char_t)0x00U;   /* only first byte differs */
}

static void run_tc012(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 16U);
}

static bool_t check_tc012(void)
{
    return (s_result < 0) ? TRUE : FALSE;
}

/* --- TC-CMP-013: difference at the middle byte -------------------- */

static void setup_tc013(void)
{
    fill_pattern(s_buf1, 16U, 0x50U);
    fill_pattern(s_buf2, 16U, 0x50U);
    s_buf2[8] = (char_t)0xFFU;   /* middle byte of buf2 is larger */
}

static void run_tc013(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 16U);
}

static bool_t check_tc013(void)
{
    return (s_result < 0) ? TRUE : FALSE;
}

/* --- TC-CMP-014: bytes beyond size are ignored -------------------- */
/*     Buffers match for the first 8 bytes; byte 9 differs.          */
/*     Comparing only 8 bytes must return 0.                         */

static void setup_tc014(void)
{
    fill_pattern(s_buf1, 16U, 0x60U);
    fill_pattern(s_buf2, 16U, 0x60U);
    s_buf2[8] = (char_t)0xFFU;   /* differs outside the compare range */
}

static void run_tc014(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 8U);
}

static bool_t check_tc014(void)
{
    return (s_result == 0) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test group 5: unsigned interpretation of bytes                     */
/* ================================================================== */

/* --- TC-CMP-015: 0x01 vs 0xFF interpreted as unsigned ------------- */
/*     As unsigned: 0x01 (1) < 0xFF (255)  =>  result < 0           */
/*     (Would be opposite if signed: -1 < 1)                         */

static void setup_tc015(void)
{
    s_buf1[0] = (char_t)0x01U;
    s_buf2[0] = (char_t)0xFFU;
}

static void run_tc015(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc015(void)
{
    return (s_result < 0) ? TRUE : FALSE;
}

/* --- TC-CMP-016: 0xFF vs 0x01 interpreted as unsigned ------------- */
/*     As unsigned: 0xFF (255) > 0x01 (1)  =>  result > 0           */

static void setup_tc016(void)
{
    s_buf1[0] = (char_t)0xFFU;
    s_buf2[0] = (char_t)0x01U;
}

static void run_tc016(void)
{
    s_result = memory_ops_utils_cmp(s_buf1, s_buf2, 1U);
}

static bool_t check_tc016(void)
{
    return (s_result > 0) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test table                                                           */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    /* Group 1 – equal memory areas */
    { "TC-CMP-001: identical buffers return 0",                     setup_tc001, run_tc001, check_tc001 },
    { "TC-CMP-002: single equal byte returns 0",                    setup_tc002, run_tc002, check_tc002 },
    { "TC-CMP-003: zero-size compare always returns 0",             setup_tc003, run_tc003, check_tc003 },
    { "TC-CMP-004: all-zeros buffers return 0",                     setup_tc004, run_tc004, check_tc004 },
    { "TC-CMP-005: all-0xFF buffers return 0",                      setup_tc005, run_tc005, check_tc005 },

    /* Group 2 – src1 < src2 (negative result) */
    { "TC-CMP-006: first byte src1 < src2 returns negative",        setup_tc006, run_tc006, check_tc006 },
    { "TC-CMP-007: last byte differs, src1 < src2 returns negative", setup_tc007, run_tc007, check_tc007 },
    { "TC-CMP-008: exact negative delta value is correct",          setup_tc008, run_tc008, check_tc008 },

    /* Group 3 – src1 > src2 (positive result) */
    { "TC-CMP-009: first byte src1 > src2 returns positive",        setup_tc009, run_tc009, check_tc009 },
    { "TC-CMP-010: last byte differs, src1 > src2 returns positive", setup_tc010, run_tc010, check_tc010 },
    { "TC-CMP-011: exact positive delta value is correct",          setup_tc011, run_tc011, check_tc011 },

    /* Group 4 – difference position */
    { "TC-CMP-012: difference at first byte detected",              setup_tc012, run_tc012, check_tc012 },
    { "TC-CMP-013: difference at middle byte detected",             setup_tc013, run_tc013, check_tc013 },
    { "TC-CMP-014: bytes beyond size are ignored",                  setup_tc014, run_tc014, check_tc014 },

    /* Group 5 – unsigned byte interpretation */
    { "TC-CMP-015: 0x01 vs 0xFF treated as unsigned (result < 0)", setup_tc015, run_tc015, check_tc015 },
    { "TC-CMP-016: 0xFF vs 0x01 treated as unsigned (result > 0)", setup_tc016, run_tc016, check_tc016 },
};

/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(
            "memory_ops_utils_cmp",
            s_cases,
            sizeof(s_cases) / sizeof(s_cases[0]));

    while(1);
}
