#include "types_usr.h"
#include "mmio_io64_krn.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "mmio_io64_set_bit_tc.h"

static uint64_t               s_mmio_reg;            /* Simulated MMIO register */
static addr_t                 s_mmio_reg_addr;       /* Address of simulated MMIO register */
static mmio_io64_set_bit_tc_t s_tc;                  /* Current test case */

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    /* Initialize buffers with initial values */
    s_mmio_reg      = s_tc.input.init_byte;
    s_mmio_reg_addr = (addr_t)&s_mmio_reg;
}

void run(void)
{
    for (uint8_t call_idx = 0; call_idx < s_tc.input.number_of_sets; call_idx++)
    {
        mmio_io64_set_bit(&s_mmio_reg, s_tc.input.bit_index_to_set[call_idx]);
    }
}

void check(void)
{
    /* Check expected value */
    SPEC_EXPECT_EQ_U64(s_mmio_reg, s_tc.expected.expected_result);

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
