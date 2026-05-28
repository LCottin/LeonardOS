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
 *  TC-001  Clear bit 0 of 0xFF
 * ========================================================= */
static void setup_tc001(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc001(void)
{
    mmio_io8_clear_bit(s_addr, 0U);
}

static bool_t check_tc001(void)
{
    return (read_reg() == 0xFEU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-002  Clear bit 7 of 0xFF
 * ========================================================= */
static void setup_tc002(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc002(void)
{
    mmio_io8_clear_bit(s_addr, 7U);
}

static bool_t check_tc002(void)
{
    return (read_reg() == 0x7FU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-003  Clear bit 3 of 0xFF
 * ========================================================= */
static void setup_tc003(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc003(void)
{
    mmio_io8_clear_bit(s_addr, 3U);
}

static bool_t check_tc003(void)
{
    return (read_reg() == 0xF7U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-004  Clear already-cleared bit – register unchanged
 * ========================================================= */
static void setup_tc004(void)
{
    s_mmio_reg = 0x00U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc004(void)
{
    mmio_io8_clear_bit(s_addr, 4U);
}

static bool_t check_tc004(void)
{
    return (read_reg() == 0x00U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-005  Only the target bit is cleared, others preserved
 *          0b10101010 clear bit 1 → 0b10101000
 * ========================================================= */
static void setup_tc005(void)
{
    s_mmio_reg = 0xAAU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc005(void)
{
    mmio_io8_clear_bit(s_addr, 1U);
}

static bool_t check_tc005(void)
{
    return (read_reg() == 0xA8U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-006  Only the target bit is cleared, others preserved
 *          0b01010101 clear bit 6 → 0b00010101
 * ========================================================= */
static void setup_tc006(void)
{
    s_mmio_reg = 0x55U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc006(void)
{
    mmio_io8_clear_bit(s_addr, 6U);
}

static bool_t check_tc006(void)
{
    return (read_reg() == 0x15U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-007  Clear bit 4 of 0xFF
 * ========================================================= */
static void setup_tc007(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc007(void)
{
    mmio_io8_clear_bit(s_addr, 4U);
}

static bool_t check_tc007(void)
{
    return (read_reg() == 0xEFU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-008  Invalid bit index 8 – register must not change
 * ========================================================= */
static void setup_tc008(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc008(void)
{
    mmio_io8_clear_bit(s_addr, 8U);
}

static bool_t check_tc008(void)
{
    return (read_reg() == 0xFFU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-009  Invalid bit index 255 – register must not change
 * ========================================================= */
static void setup_tc009(void)
{
    s_mmio_reg = 0xAAU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc009(void)
{
    mmio_io8_clear_bit(s_addr, 255U);
}

static bool_t check_tc009(void)
{
    return (read_reg() == 0xAAU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-010  Invalid bit index 9 – register must not change
 * ========================================================= */
static void setup_tc010(void)
{
    s_mmio_reg = 0x55U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc010(void)
{
    mmio_io8_clear_bit(s_addr, 9U);
}

static bool_t check_tc010(void)
{
    return (read_reg() == 0x55U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-011  Clear bit 0 of 0x01 → 0x00 (all bits zero)
 * ========================================================= */
static void setup_tc011(void)
{
    s_mmio_reg = 0x01U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc011(void)
{
    mmio_io8_clear_bit(s_addr, 0U);
}

static bool_t check_tc011(void)
{
    return (read_reg() == 0x00U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-012  Clear bit 7 of 0x80 → 0x00 (all bits zero)
 * ========================================================= */
static void setup_tc012(void)
{
    s_mmio_reg = 0x80U;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc012(void)
{
    mmio_io8_clear_bit(s_addr, 7U);
}

static bool_t check_tc012(void)
{
    return (read_reg() == 0x00U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-013  Sequential clears: clear bit 2, then bit 5 of 0xFF
 * ========================================================= */
static void setup_tc013(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc013(void)
{
    mmio_io8_clear_bit(s_addr, 2U);
    mmio_io8_clear_bit(s_addr, 5U);
}

static bool_t check_tc013(void)
{
    return (read_reg() == 0xDBU) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-014  Clear same bit twice – idempotent, register unchanged
 *          after second call
 * ========================================================= */
static void setup_tc014(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc014(void)
{
    mmio_io8_clear_bit(s_addr, 3U);
    mmio_io8_clear_bit(s_addr, 3U);
}

static bool_t check_tc014(void)
{
    return (read_reg() == 0xF7U) ? TRUE : FALSE;
}

/* =========================================================
 *  TC-015  Clear all bits one by one from 0xFF → 0x00
 * ========================================================= */
static void setup_tc015(void)
{
    s_mmio_reg = 0xFFU;
    s_addr     = (ptr_t)&s_mmio_reg;
}

static void run_tc015(void)
{
    for (uint8_t idx = 0U; idx < 8U; idx++)
    {
        mmio_io8_clear_bit(s_addr, idx);
    }
}

static bool_t check_tc015(void)
{
    return (read_reg() == 0x00U) ? TRUE : FALSE;
}

/* ================================================================== */
/* Test table                                                         */
/* ================================================================== */

static const spec_run_case_t s_cases[] =
{
    { "TC-001: Clear bit 0 of 0xFF → 0xFE",                        setup_tc001, run_tc001, check_tc001 },
    { "TC-002: Clear bit 7 of 0xFF → 0x7F",                        setup_tc002, run_tc002, check_tc002 },
    { "TC-003: Clear bit 3 of 0xFF → 0xF7",                        setup_tc003, run_tc003, check_tc003 },
    { "TC-004: Clear already-cleared bit, register unchanged",     setup_tc004, run_tc004, check_tc004 },
    { "TC-005: Only target bit cleared, others preserved (0xAA)",  setup_tc005, run_tc005, check_tc005 },
    { "TC-006: Only target bit cleared, others preserved (0x55)",  setup_tc006, run_tc006, check_tc006 },
    { "TC-007: Clear bit 4 of 0xFF → 0xEF",                        setup_tc007, run_tc007, check_tc007 },
    { "TC-008: Invalid index 8, register unchanged",               setup_tc008, run_tc008, check_tc008 },
    { "TC-009: Invalid index 255, register unchanged",             setup_tc009, run_tc009, check_tc009 },
    { "TC-010: Invalid index 9, register unchanged",               setup_tc010, run_tc010, check_tc010 },
    { "TC-011: Clear bit 0 of 0x01 → 0x00",                        setup_tc011, run_tc011, check_tc011 },
    { "TC-012: Clear bit 7 of 0x80 → 0x00",                        setup_tc012, run_tc012, check_tc012 },
    { "TC-013: Sequential clears bit 2 and bit 5 of 0xFF → 0xDB",  setup_tc013, run_tc013, check_tc013 },
    { "TC-014: Clear same bit twice, idempotent → 0xF7",           setup_tc014, run_tc014, check_tc014 },
    { "TC-015: Clear all 8 bits one by one, 0xFF → 0x00",          setup_tc015, run_tc015, check_tc015 },
};

/* ================================================================== */
/* Entry point                                                        */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(
            "mmio_io8_clear_bit",
            s_cases,
            sizeof(s_cases) / sizeof(s_cases[0]));

    while(1);
}
