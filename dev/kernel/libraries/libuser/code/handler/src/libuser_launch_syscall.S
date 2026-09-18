.section .text
.global  libuser_launch_syscall
.type    libuser_launch_syscall, %function

libuser_launch_syscall:

    svc     #0      /* Launch svc instruction to trigger interruption on kernel side */
    ret
