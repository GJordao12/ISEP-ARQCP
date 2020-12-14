.section .data

.section .text

        .global sum_n    

sum_n:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl 8(%ebp), %edx
        movl $0, %eax

start:
        cmp $0, %edx
        jle end
        addl %edx, %eax
        decl %edx
        loop start

end:
        movl %ebp, %esp
        popl %ebp
        ret
