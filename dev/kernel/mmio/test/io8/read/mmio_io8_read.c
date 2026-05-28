#include "types_usr.h"
#include "mmio_io8_krn.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"

/* ================================================================== */
/* Shared data                                                        */
/* ================================================================== */

static uint8_t s_mmio_reg;   /* simulated MMIO register                 */
static ptr_t   s_addr;       /* address passed to the function          */
static uint8_t s_result;     /* value returned by the function          */
static uint8_t s_result2;    /* second value for test TC-010 and TC-011 */

/* =========================================================
 *  TC-001  Read 0x00
 * ========================================================= */
static void setup_tc001(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc001(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc001(void)
{
    return (s_result == 0x00U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-002  Read 0xFF
 * ========================================================= */
static void setup_tc002(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc002(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc002(void)
{
    return (s_result == 0xFFU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-003  Read 0x01 (only LSB set)
 * ========================================================= */
static void setup_tc003(void)
{
    s_mmio_reg = 0x01U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc003(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc003(void)
{
    return (s_result == 0x01U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-004  Read 0x80 (only MSB set)
 * ========================================================= */
static void setup_tc004(void)
{
    s_mmio_reg = 0x80U;
    s_addr     = (ptr_t)&s_mmio_reg;
}
static void run_tc004(void)
{
    s_result = mmio_io8_read(s_addr);
}
static bool_t check_tc004(void)
{
    return (s_result == 0x80U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-005  Read 0xAA (alternating bits 10101010)
 * ========================================================= */
static void setup_tc005(void)
{
    s_mmio_reg = 0xAAU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc005(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc005(void)
{
    return (s_result == 0xAAU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-006  Read 0x55 (alternating bits 01010101)
 * ========================================================= */
static void setup_tc006(void)
{
    s_mmio_reg = 0x55U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc006(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc006(void)
{
    return (s_result == 0x55U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-007  Read arbitrary value 0x3C
 * ========================================================= */
static void setup_tc007(void)
{
    s_mmio_reg = 0x3CU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc007(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc007(void)
{
    return (s_result == 0x3CU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-008  Return value matches register exactly – not inverted
 *          Use 0xA5 as a non-symmetric pattern
 * ========================================================= */
static void setup_tc008(void)
{
    s_mmio_reg = 0xA5U;
    s_addr     = (ptr_t)&s_mmio_reg;
}
static void run_tc008(void)
{
    s_result = mmio_io8_read(s_addr);
}
static bool_t check_tc008(void)
{
    return (s_result == 0xA5U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-009  Register not modified by read – value preserved after call
 * ========================================================= */
static void setup_tc009(void)
{
    s_mmio_reg = 0xC3U;
    s_addr     = (ptr_t)&s_mmio_reg;
}
static void run_tc009(void)
{
    s_result = mmio_io8_read(s_addr);
}
static bool_t check_tc009(void)
{
    return (s_mmio_reg == 0xC3U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-010  Read twice – same value returned both times
 * ========================================================= */
static void setup_tc010(void)
{
    s_mmio_reg = 0x5AU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc010(void)
{
    s_result  = mmio_io8_read(s_addr);
    s_result2 = mmio_io8_read(s_addr);
}

static bool_t check_tc010(void)
{
    return (s_result == s_result2) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-011  Read reflects updated register value
 *          Write 0x0F first, read, then update to 0xF0, read again
 * ========================================================= */
static void setup_tc011(void)
{
    s_mmio_reg = 0x0FU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc011(void)
{
    s_result   = mmio_io8_read(s_addr);
    s_mmio_reg = 0xF0U;
    s_result2  = mmio_io8_read(s_addr);
}

static bool_t check_tc011(void)
{
    return ((s_result == 0x0FU) && (s_result2 == 0xF0U)) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-012  Read 0x0F (lower nibble only)
 * ========================================================= */
static void setup_tc012(void)
{
    s_mmio_reg = 0x0FU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc012(void)
{
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc012(void)
{
    return (s_result == 0x0FU) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test table                                                         */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    { "TC-001: Read 0x00",                                             setup_tc001, run_tc001, check_tc001 },
    { "TC-002: Read 0xFF",                                             setup_tc002, run_tc002, check_tc002 },
    { "TC-003: Read 0x01 (LSB only)",                                  setup_tc003, run_tc003, check_tc003 },
    { "TC-004: Read 0x80 (MSB only)",                                  setup_tc004, run_tc004, check_tc004 },
    { "TC-005: Read 0xAA (alternating 1s)",                            setup_tc005, run_tc005, check_tc005 },
    { "TC-006: Read 0x55 (alternating 0s)",                            setup_tc006, run_tc006, check_tc006 },
    { "TC-007: Read arbitrary value 0x3C",                             setup_tc007, run_tc007, check_tc007 },
    { "TC-008: Return value matches register exactly, not inverted",   setup_tc008, run_tc008, check_tc008 },
    { "TC-009: Register not modified by read",                         setup_tc009, run_tc009, check_tc009 },
    { "TC-010: Read twice returns same value",                         setup_tc010, run_tc010, check_tc010 },
    { "TC-011: Read reflects updated register value",                  setup_tc011, run_tc011, check_tc011 },
    { "TC-012: Read 0x0F (lower nibble only)",                         setup_tc012, run_tc012, check_tc012 },
};

/* ================================================================== */
/* Entry point                                                        */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(
            "mmio_io8_read",
            s_cases,
            sizeof(s_cases) / sizeof(s_cases[0]));

    while(1);
}
