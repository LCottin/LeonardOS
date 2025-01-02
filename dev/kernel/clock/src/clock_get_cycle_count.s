.section .text
.global  clock_get_cycle_count
.type    clock_get_cycle_count, %function

clock_get_cycle_count:
    mrs     x0, CNTVCT_EL0   /* Read the current value of the virtual counter */
    br      lr               /* Return from subroutine */
