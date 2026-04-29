#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "memory_ops_usr.h"

/* ================================================================== */
/* Shared buffers                                                       */
/* ================================================================== */

#define BUFFER_SIZE    128U
#define SENTINEL_BYTE  0xAAU

static char_t s_dst[BUFFER_SIZE];

/* ================================================================== */
/* Helper: verify every byte in a range equals an expected value      */
/* ================================================================== */

static bool_t range_equals(const char_t *buf, size_t size, uint8_t expected)
{
    size_t idx;

    for (idx = 0U; idx < size; idx++)
    {
        if ((uint8_t)buf[idx] != expected)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/* ================================================================== */
/* Test group 1: basic correctness                                     */
/* ================================================================== */

/* --- TC-SET-001: set a normal buffer to 0x00 ---------------------- */

static void setup_tc001(void)
{
    spec_utils_memset(s_dst, 0xFFU, BUFFER_SIZE);
}

static void run_tc001(void)
{
    memory_ops_utils_set(s_dst, 0x00, 32U);
}

static bool_t check_tc001(void)
{
    return range_equals(s_dst, 32U, 0x00U);
}

/* --- TC-SET-002: set a buffer to 0xFF ----------------------------- */

static void setup_tc002(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc002(void)
{
    memory_ops_utils_set(s_dst, 0xFF, 32U);
}

static bool_t check_tc002(void)
{
    return range_equals(s_dst, 32U, 0xFFU);
}

/* --- TC-SET-003: set a buffer to an arbitrary mid-range value ----- */

static void setup_tc003(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc003(void)
{
    memory_ops_utils_set(s_dst, 0x5A, 32U);
}

static bool_t check_tc003(void)
{
    return range_equals(s_dst, 32U, 0x5AU);
}

/* --- TC-SET-004: return value equals dest pointer ----------------- */

static ptr_t s_tc004_ret = NULL_PTR;

static void setup_tc004(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc004(void)
{
    s_tc004_ret = memory_ops_utils_set(s_dst, 0x42, 16U);
}

static bool_t check_tc004(void)
{
    return (s_tc004_ret == (ptr_t)s_dst) ? TRUE : FALSE;
}

/* --- TC-SET-005: zero-size set must leave destination unchanged ---- */

static void setup_tc005(void)
{
    spec_utils_memset(s_dst, SENTINEL_BYTE, BUFFER_SIZE);
}

static void run_tc005(void)
{
    memory_ops_utils_set(s_dst, 0x00, 0U);
}

static bool_t check_tc005(void)
{
    return range_equals(s_dst, BUFFER_SIZE, SENTINEL_BYTE);
}

/* ================================================================== */
/* Test group 2: value truncation to uint8_t                          */
/* ================================================================== */

/* --- TC-SET-006: int32 value 0x1234AB only low byte 0xAB stored --- */

static void setup_tc006(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc006(void)
{
    memory_ops_utils_set(s_dst, 0x1234AB, 16U);
}

static bool_t check_tc006(void)
{
    return range_equals(s_dst, 16U, 0xABU);
}

/* --- TC-SET-007: negative int32 -1 (0xFFFFFFFF) stores 0xFF ------- */

static void setup_tc007(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc007(void)
{
    memory_ops_utils_set(s_dst, -1, 16U);
}

static bool_t check_tc007(void)
{
    return range_equals(s_dst, 16U, 0xFFU);
}

/* ================================================================== */
/* Test group 3: size boundary cases around MEMORY_ALIGNMENT (8)      */
/* ================================================================== */

/* --- TC-SET-008: single-byte set ---------------------------------- */

static void setup_tc008(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc008(void)
{
    memory_ops_utils_set(s_dst, 0x7F, 1U);
}

static bool_t check_tc008(void)
{
    return ((uint8_t)s_dst[0] == 0x7FU) ? TRUE : FALSE;
}

/* --- TC-SET-009: size = MEMORY_ALIGNMENT - 1 (7 bytes) ------------ */

static void setup_tc009(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc009(void)
{
    memory_ops_utils_set(s_dst, 0xBB, 7U);
}

static bool_t check_tc009(void)
{
    return range_equals(s_dst, 7U, 0xBBU);
}

/* --- TC-SET-010: size = MEMORY_ALIGNMENT (8 bytes) ---------------- */

static void setup_tc010(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc010(void)
{
    memory_ops_utils_set(s_dst, 0xCC, 8U);
}

static bool_t check_tc010(void)
{
    return range_equals(s_dst, 8U, 0xCCU);
}

/* --- TC-SET-011: size = MEMORY_ALIGNMENT + 1 (9 bytes) ------------ */

static void setup_tc011(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc011(void)
{
    memory_ops_utils_set(s_dst, 0xDD, 9U);
}

static bool_t check_tc011(void)
{
    return range_equals(s_dst, 9U, 0xDDU);
}

/* --- TC-SET-012: size = 2 * MEMORY_ALIGNMENT (16 bytes) ----------- */

static void setup_tc012(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc012(void)
{
    memory_ops_utils_set(s_dst, 0xEE, 16U);
}

static bool_t check_tc012(void)
{
    return range_equals(s_dst, 16U, 0xEEU);
}

/* --- TC-SET-013: large size (full BUFFER_SIZE, multiple of 8) ----- */

static void setup_tc013(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc013(void)
{
    memory_ops_utils_set(s_dst, 0x55, BUFFER_SIZE);
}

static bool_t check_tc013(void)
{
    return range_equals(s_dst, BUFFER_SIZE, 0x55U);
}

/* ================================================================== */
/* Test group 4: alignment edge-cases                                  */
/* ================================================================== */

/* --- TC-SET-014: set to a +1-byte-misaligned destination ---------- */
/*     Forces the byte-by-byte pre-alignment loop inside the impl.   */

static void setup_tc014(void)
{
    spec_utils_memset(s_dst, 0x00U, BUFFER_SIZE);
}

static void run_tc014(void)
{
    memory_ops_utils_set(s_dst + 1U, 0x99, 15U);
}

static bool_t check_tc014(void)
{
    return range_equals(s_dst + 1U, 15U, 0x99U);
}

/* --- TC-SET-015: no bytes written beyond requested size ----------- */
/*     Sentinel bytes outside the set region must be untouched.      */

static void setup_tc015(void)
{
    spec_utils_memset(s_dst, SENTINEL_BYTE, BUFFER_SIZE);
}

static void run_tc015(void)
{
    memory_ops_utils_set(s_dst, 0x11, 10U);
}

static bool_t check_tc015(void)
{
    size_t idx;

    /* Bytes 0-9 must equal 0x11 */
    if (range_equals(s_dst, 10U, 0x11U) == FALSE)
    {
        return FALSE;
    }

    /* Bytes 10+ must still be the sentinel */
    for (idx = 10U; idx < BUFFER_SIZE; idx++)
    {
        if ((uint8_t)s_dst[idx] != SENTINEL_BYTE)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/* ================================================================== */
/* Test table                                                           */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    /* Group 1 – basic correctness */
    { "TC-SET-001: sets buffer to 0x00 correctly",                  setup_tc001, run_tc001, check_tc001 },
    { "TC-SET-002: sets buffer to 0xFF correctly",                  setup_tc002, run_tc002, check_tc002 },
    { "TC-SET-003: sets buffer to arbitrary value 0x5A",            setup_tc003, run_tc003, check_tc003 },
    { "TC-SET-004: return value equals dest pointer",               setup_tc004, run_tc004, check_tc004 },
    { "TC-SET-005: zero-size set leaves destination unchanged",     setup_tc005, run_tc005, check_tc005 },

    /* Group 2 – value truncation to uint8_t */
    { "TC-SET-006: int32 0x1234AB stores only low byte 0xAB",       setup_tc006, run_tc006, check_tc006 },
    { "TC-SET-007: negative value -1 stores 0xFF",                  setup_tc007, run_tc007, check_tc007 },

    /* Group 3 – size boundaries around MEMORY_ALIGNMENT */
    { "TC-SET-008: single-byte set",                                setup_tc008, run_tc008, check_tc008 },
    { "TC-SET-009: size = MEMORY_ALIGNMENT - 1 (7 bytes)",          setup_tc009, run_tc009, check_tc009 },
    { "TC-SET-010: size = MEMORY_ALIGNMENT (8 bytes)",              setup_tc010, run_tc010, check_tc010 },
    { "TC-SET-011: size = MEMORY_ALIGNMENT + 1 (9 bytes)",          setup_tc011, run_tc011, check_tc011 },
    { "TC-SET-012: size = 2 * MEMORY_ALIGNMENT (16 bytes)",         setup_tc012, run_tc012, check_tc012 },
    { "TC-SET-013: large size (BUFFER_SIZE, multiple of 8)",        setup_tc013, run_tc013, check_tc013 },

    /* Group 4 – alignment edge-cases */
    { "TC-SET-014: misaligned destination (+1 byte offset)",        setup_tc014, run_tc014, check_tc014 },
    { "TC-SET-015: no bytes written beyond requested size",         setup_tc015, run_tc015, check_tc015 },
};

/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(
            "memory_ops_utils_set",
            s_cases,
            sizeof(s_cases) / sizeof(s_cases[0]));

    while(1);
}
