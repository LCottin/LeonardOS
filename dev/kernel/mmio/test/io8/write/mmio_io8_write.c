#include "types_usr.h"
#include "mmio_io8_krn.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"

/* ================================================================== */
/* Shared data                                                        */
/* ================================================================== */

static uint8_t s_mmio_reg;   /* simulated MMIO register          */
static ptr_t   s_addr;       /* address passed to the function   */

/* ================================================================== */
/* Helper: read the simulated register                                */
/* ================================================================== */

static uint8_t read_reg(void)
{
    return *(volatile uint8_t *)s_addr;
}

/* =========================================================
 *  TC-001  Write 0x00 to register initialised at 0xFF
 * ========================================================= */
static void setup_tc001(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc001(void)
{
    mmio_io8_write(s_addr, 0x00U);
}

static bool_t check_tc001(void)
{
    return (read_reg() == 0x00U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-002  Write 0xFF to register initialised at 0x00
 * ========================================================= */
static void setup_tc002(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc002(void)
{
    mmio_io8_write(s_addr, 0xFFU);
}

static bool_t check_tc002(void)
{
    return (read_reg() == 0xFFU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-003  Write 0x01 (LSB only)
 * ========================================================= */
static void setup_tc003(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc003(void)
{
    mmio_io8_write(s_addr, 0x01U);
}

static bool_t check_tc003(void)
{
    return (read_reg() == 0x01U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-004  Write 0x80 (MSB only)
 * ========================================================= */
static void setup_tc004(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc004(void)
{
    mmio_io8_write(s_addr, 0x80U);
}

static bool_t check_tc004(void)
{
    return (read_reg() == 0x80U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-005  Write 0xAA (alternating 10101010)
 * ========================================================= */
static void setup_tc005(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc005(void)
{
    mmio_io8_write(s_addr, 0xAAU);
}

static bool_t check_tc005(void)
{
    return (read_reg() == 0xAAU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-006  Write 0x55 (alternating 01010101)
 * ========================================================= */
static void setup_tc006(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc006(void)
{
    mmio_io8_write(s_addr, 0x55U);
}

static bool_t check_tc006(void)
{
    return (read_reg() == 0x55U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-007  Write arbitrary value 0x3C
 * ========================================================= */
static void setup_tc007(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc007(void)
{
    mmio_io8_write(s_addr, 0x3CU);
}

static bool_t check_tc007(void)
{
    return (read_reg() == 0x3CU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-008  Write non-symmetric pattern 0xA5
 *          Confirms value not inverted or masked
 * ========================================================= */
static void setup_tc008(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc008(void)
{
    mmio_io8_write(s_addr, 0xA5U);
}

static bool_t check_tc008(void)
{
    return (read_reg() == 0xA5U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-009  Write overwrites previous content entirely
 *          Initial 0xAA overwritten by 0x55
 * ========================================================= */
static void setup_tc009(void)
{
    s_mmio_reg = 0xAAU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc009(void)
{
    mmio_io8_write(s_addr, 0x55U);
}

static bool_t check_tc009(void)
{
    return (read_reg() == 0x55U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-010  Write same value twice – register holds last written value
 * ========================================================= */
static void setup_tc010(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc010(void)
{
    mmio_io8_write(s_addr, 0x3CU);
    mmio_io8_write(s_addr, 0x3CU);
}

static bool_t check_tc010(void)
{
    return (read_reg() == 0x3CU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-011  Sequential writes – register holds last written value
 *          Write 0x0F then 0xF0
 * ========================================================= */
static void setup_tc011(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc011(void)
{
    mmio_io8_write(s_addr, 0x0FU);
    mmio_io8_write(s_addr, 0xF0U);
}

static bool_t check_tc011(void)
{
    return (read_reg() == 0xF0U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-012  Write then read back – confirms round trip with read function
 *          Write 0xC3, read back via mmio_io8_read
 * ========================================================= */
static uint8_t s_result;
static void setup_tc012(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc012(void)
{
    mmio_io8_write(s_addr, 0xC3U);
    s_result = mmio_io8_read(s_addr);
}

static bool_t check_tc012(void)
{
    return (s_result == 0xC3U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-013  Write to register initialised with same value – no change
 * ========================================================= */
static void setup_tc013(void)
{
    s_mmio_reg = 0x5AU;
    s_addr     = (ptr_t)&s_mmio_reg;

}
static void run_tc013(void)
{
    mmio_io8_write(s_addr, 0x5AU);
}

static bool_t check_tc013(void)
{
    return (read_reg() == 0x5AU) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test table                                                         */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    { "TC-001: Write 0x00 overwrites 0xFF",                             setup_tc001, run_tc001, check_tc001 },
    { "TC-002: Write 0xFF overwrites 0x00",                             setup_tc002, run_tc002, check_tc002 },
    { "TC-003: Write 0x01 (LSB only)",                                  setup_tc003, run_tc003, check_tc003 },
    { "TC-004: Write 0x80 (MSB only)",                                  setup_tc004, run_tc004, check_tc004 },
    { "TC-005: Write 0xAA (alternating 1s)",                            setup_tc005, run_tc005, check_tc005 },
    { "TC-006: Write 0x55 (alternating 0s)",                            setup_tc006, run_tc006, check_tc006 },
    { "TC-007: Write arbitrary value 0x3C",                             setup_tc007, run_tc007, check_tc007 },
    { "TC-008: Write non-symmetric 0xA5, value not inverted or masked", setup_tc008, run_tc008, check_tc008 },
    { "TC-009: Write overwrites previous content entirely",             setup_tc009, run_tc009, check_tc009 },
    { "TC-010: Write same value twice, register holds written value",   setup_tc010, run_tc010, check_tc010 },
    { "TC-011: Sequential writes, register holds last written value",   setup_tc011, run_tc011, check_tc011 },
    { "TC-012: Write then read back, confirms round trip",              setup_tc012, run_tc012, check_tc012 },
    { "TC-013: Write same value as initial, register unchanged",        setup_tc013, run_tc013, check_tc013 },
};

/* ================================================================== */
/* Entry point                                                        */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(
            "mmio_io8_write",
            s_cases,
            sizeof(s_cases) / sizeof(s_cases[0]));

    while(1);
}
