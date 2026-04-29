#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "memory_ops_usr.h"

/* ================================================================== */
/* Shared buffers                                                       */
/* ================================================================== */

#define BUFFER_SIZE 128U

static char_t s_dst[BUFFER_SIZE];
static char_t s_src[BUFFER_SIZE];

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
/* Test group 1: basic correctness                                     */
/* ================================================================== */

/* --- TC-COPY-001: copy a short aligned string -------------------- */

static const char_t *s_tc001_src = "LeonardOS";

static void setup_tc001(void)
{
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc001(void)
{
    memory_ops_utils_copy(s_dst, s_tc001_src, 10U);
}

static bool_t check_tc001(void)
{
    return (spec_utils_memcmp(s_dst, s_tc001_src, 10U) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-002: zero-size copy must leave destination unchanged -- */

static void setup_tc002(void)
{
    spec_utils_memset(s_dst, 0xAB, sizeof(s_dst));
}

static void run_tc002(void)
{
    memory_ops_utils_copy(s_dst, "anything", 0U);
}

static bool_t check_tc002(void)
{
    /* Every byte must still be 0xAB */
    size_t idx;

    for (idx = 0U; idx < sizeof(s_dst); idx++)
    {
        if ((uint8_t)s_dst[idx] != 0xABU)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/* --- TC-COPY-003: return value equals dest pointer ----------------- */

static ptr_t s_tc003_ret = NULL_PTR;

static void setup_tc003(void)
{
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc003(void)
{
    s_tc003_ret = memory_ops_utils_copy(s_dst, "hello", 6U);
}

static bool_t check_tc003(void)
{
    return (s_tc003_ret == (ptr_t)s_dst) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test group 2: alignment edge-cases                                  */
/* ================================================================== */

/* --- TC-COPY-004: copy exactly MEMORY_ALIGNMENT (8) bytes ---------- */

static const uint8_t s_tc004_pattern[8U] = {0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x07U, 0x08U};

static void setup_tc004(void)
{
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc004(void)
{
    memory_ops_utils_copy(s_dst, s_tc004_pattern, 8U);
}

static bool_t check_tc004(void)
{
    return (spec_utils_memcmp(s_dst, s_tc004_pattern, 8U) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-005: copy a size that is NOT a multiple of 8 ---------- */
/*     Tests the tail-byte path after bulk 8-byte copy               */

static void setup_tc005(void)
{
    fill_pattern(s_src, 19U, 0x10U);
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc005(void)
{
    memory_ops_utils_copy(s_dst, s_src, 19U);
}

static bool_t check_tc005(void)
{
    return (spec_utils_memcmp(s_dst, s_src, 19U) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-006: copy from a +1-byte-misaligned source ------------ */
/*     Forces the byte-by-byte pre-alignment loop on the src side     */

static void setup_tc006(void)
{
    fill_pattern(s_src, BUFFER_SIZE, 0x20U);
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc006(void)
{
    /* s_src + 1 is intentionally misaligned */
    memory_ops_utils_copy(s_dst, s_src + 1U, 15U);
}

static bool_t check_tc006(void)
{
    return (spec_utils_memcmp(s_dst, s_src + 1U, 15U) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-007: copy to a +1-byte-misaligned destination --------- */

static void setup_tc007(void)
{
    fill_pattern(s_src, BUFFER_SIZE, 0x30U);
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc007(void)
{
    memory_ops_utils_copy(s_dst + 1U, s_src, 15U);
}

static bool_t check_tc007(void)
{
    return (spec_utils_memcmp(s_dst + 1U, s_src, 15U) == 0) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test group 3: data-integrity across sizes                           */
/* ================================================================== */

/* --- TC-COPY-008: single-byte copy --------------------------------- */

static void setup_tc008(void)
{
    s_src[0] = (char_t)0x7FU;
    s_dst[0] = (char_t)0x00U;
}

static void run_tc008(void)
{
    memory_ops_utils_copy(s_dst, s_src, 1U);
}

static bool_t check_tc008(void)
{
    return ((uint8_t)s_dst[0] == 0x7FU) ? TRUE : FALSE;
}

/* --- TC-COPY-009: large copy (multiple of 8, fully aligned) -------- */

static void setup_tc009(void)
{
    fill_pattern(s_src, BUFFER_SIZE, 0x00U);
    spec_utils_memset(s_dst, 0xFF, BUFFER_SIZE);
}

static void run_tc009(void)
{
    memory_ops_utils_copy(s_dst, s_src, BUFFER_SIZE);
}

static bool_t check_tc009(void)
{
    return (spec_utils_memcmp(s_dst, s_src, BUFFER_SIZE) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-010: copy does NOT clobber bytes beyond size ----------- */

static void setup_tc010(void)
{
    fill_pattern(s_src, BUFFER_SIZE, 0xA0U);
    spec_utils_memset(s_dst, 0xBBU, BUFFER_SIZE);
}

static void run_tc010(void)
{
    memory_ops_utils_copy(s_dst, s_src, 10U);
}

static bool_t check_tc010(void)
{
    size_t idx;
    /* Bytes 0-9 must match src */
    if (spec_utils_memcmp(s_dst, s_src, 10U) != 0)
    {
        return FALSE;
    }
    /* Bytes 10+ must still be 0xBB */
    for (idx = 10U; idx < BUFFER_SIZE; idx++)
    {
        if ((uint8_t)s_dst[idx] != 0xBBU)
        {
            return FALSE;
        }
    }
    return TRUE;
}

/* --- TC-COPY-011: all-zeros source copies correctly ---------------- */

static void setup_tc011(void)
{
    spec_utils_memset(s_src, 0x00, 32U);
    spec_utils_memset(s_dst, 0xFFU, 32U);
}

static void run_tc011(void)
{
    memory_ops_utils_copy(s_dst, s_src, 32U);
}

static bool_t check_tc011(void)
{
    size_t idx;

    for (idx = 0U; idx < 32U; idx++)
    {
        if ((uint8_t)s_dst[idx] != 0x00U)
        {
            return FALSE;
        }
    }
    
    return TRUE;
}

/* --- TC-COPY-012: all-0xFF source copies correctly ----------------- */

static void setup_tc012(void)
{
    spec_utils_memset(s_src, 0xFFU, 32U);
    spec_utils_memset(s_dst, 0x00U, 32U);
}

static void run_tc012(void)
{
    memory_ops_utils_copy(s_dst, s_src, 32U);
}

static bool_t check_tc012(void)
{
    size_t idx;

    for (idx = 0U; idx < 32U; idx++)
    {
        if ((uint8_t)s_dst[idx] != 0xFFU)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/* ================================================================== */
/* Test group 4: boundary sizes around MEMORY_ALIGNMENT (8 bytes)     */
/* ================================================================== */

/* --- TC-COPY-013: size = MEMORY_ALIGNMENT - 1 (7 bytes) ----------- */

static void setup_tc013(void)
{
    fill_pattern(s_src, 7U, 0x50U);
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc013(void)
{
    memory_ops_utils_copy(s_dst, s_src, 7U);
}

static bool_t check_tc013(void)
{
    return (spec_utils_memcmp(s_dst, s_src, 7U) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-014: size = MEMORY_ALIGNMENT + 1 (9 bytes) ----------- */

static void setup_tc014(void)
{
    fill_pattern(s_src, 9U, 0x60U);
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc014(void)
{
    memory_ops_utils_copy(s_dst, s_src, 9U);
}

static bool_t check_tc014(void)
{
    return (spec_utils_memcmp(s_dst, s_src, 9U) == 0) ? TRUE : FALSE;
}

/* --- TC-COPY-015: size = 2 * MEMORY_ALIGNMENT (16 bytes) ---------- */

static void setup_tc015(void)
{
    fill_pattern(s_src, 16U, 0x70U);
    spec_utils_memset(s_dst, 0, sizeof(s_dst));
}

static void run_tc015(void)
{
    memory_ops_utils_copy(s_dst, s_src, 16U);
}

static bool_t check_tc015(void)
{
    return (spec_utils_memcmp(s_dst, s_src, 16U) == 0) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test table                                                           */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    /* Group 1 – basic correctness */
    { "TC-COPY-001: copies a short aligned string correctly",    setup_tc001, run_tc001, check_tc001 },
    { "TC-COPY-002: zero-size copy leaves destination unchanged", setup_tc002, run_tc002, check_tc002 },
    { "TC-COPY-003: return value equals dest pointer",           setup_tc003, run_tc003, check_tc003 },

    /* Group 2 – alignment edge-cases */
    { "TC-COPY-004: copies exactly MEMORY_ALIGNMENT bytes",     setup_tc004, run_tc004, check_tc004 },
    { "TC-COPY-005: copies size not multiple of 8 (tail path)", setup_tc005, run_tc005, check_tc005 },
    { "TC-COPY-006: misaligned source (+1 byte offset)",        setup_tc006, run_tc006, check_tc006 },
    { "TC-COPY-007: misaligned destination (+1 byte offset)",   setup_tc007, run_tc007, check_tc007 },

    /* Group 3 – data integrity across sizes */
    { "TC-COPY-008: single-byte copy",                          setup_tc008, run_tc008, check_tc008 },
    { "TC-COPY-009: large copy (BUFFER_SIZE, fully aligned)",   setup_tc009, run_tc009, check_tc009 },
    { "TC-COPY-010: no bytes written beyond requested size",    setup_tc010, run_tc010, check_tc010 },
    { "TC-COPY-011: all-zeros source copies correctly",         setup_tc011, run_tc011, check_tc011 },
    { "TC-COPY-012: all-0xFF source copies correctly",          setup_tc012, run_tc012, check_tc012 },

    /* Group 4 – boundary sizes around MEMORY_ALIGNMENT */
    { "TC-COPY-013: size = MEMORY_ALIGNMENT - 1 (7 bytes)",     setup_tc013, run_tc013, check_tc013 },
    { "TC-COPY-014: size = MEMORY_ALIGNMENT + 1 (9 bytes)",     setup_tc014, run_tc014, check_tc014 },
    { "TC-COPY-015: size = 2 * MEMORY_ALIGNMENT (16 bytes)",    setup_tc015, run_tc015, check_tc015 },
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
