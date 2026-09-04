#include "types_usr.h"
#include "mmio_io8_krn.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "mmio_io8_read_tc.h"

static uint8_t            s_mmio_reg;           /* Simulated MMIO register */
static addr_t             s_mmio_reg_addr;      /* Address of simulated MMIO register */
static uint8_t            s_mmio_read;          /* Read data from register */
static mmio_io8_read_tc_t s_tc;                 /* Current test case */

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    /* Initialize buffers with initial values */
    s_mmio_reg      = s_tc.input.reg_value;
    s_mmio_reg_addr = (addr_t)&s_mmio_reg;
    s_mmio_read     = s_tc.input.init_byte;
}

void run(void)
{
    s_mmio_read = mmio_io8_read((cptr_t)s_mmio_reg_addr);
}

void check(void)
{
    /* Check expected value */
    SPEC_EXPECT_EQ_U8(s_mmio_read, s_tc.expected.expected_value);

    /* Check input value has not been modified */
    SPEC_EXPECT_EQ_U8(s_mmio_reg, s_tc.input.reg_value);

    /* Check that register address is unchanged */
    SPEC_EXPECT_EQ_PTR((ptr_t)&s_mmio_reg, (ptr_t)s_mmio_reg_addr);
}

/* ================================================================== */
/* Entry point                                                        */
/* ================================================================== */

void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
