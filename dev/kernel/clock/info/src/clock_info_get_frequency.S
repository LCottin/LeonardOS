.section .text
.global  clock_info_get_frequency
.type    clock_info_get_frequency, %function

clock_info_get_frequency:
    mrs     x0, CNTFRQ_EL0  /* Read the value of CNTFRQ_EL0 */
    br      lr              /* Return from subroutine */
