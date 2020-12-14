.section .data

.section .text

        .global sum_smaller    

sum_smaller:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl 8(%ebp), %eax
        movl 12(%ebp), %ecx
        movl 16(%ebp), %edx

        cmp %eax, %ecx
        jge save
        movl %ecx, (%edx)
        jmp start

save:
        movl %eax, (%edx)

start:
       cdq
       addl %ecx, %eax

end:
        movl %ebp, %esp
        popl %ebp
        ret
