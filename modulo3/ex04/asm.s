.section .data
        .global ptrvec        # char*

.section .text

        .global vec_add_one      # void

vec_add_one:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl ptrvec, %eax        # copia o valor de ptrvex para o registo %edx 

        start:
        movl (%eax), %ecx

        cmp $0, %ecx
        je end
        addl $1, %ecx
        movl %ecx, (%eax)
        jmp next_num

        next_num:
        addl $4 ,%eax

        jmp start

        end:
        
        movl %ebp, %esp
        popl %ebp
        ret
