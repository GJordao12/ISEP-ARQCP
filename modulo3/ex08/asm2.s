.section .data
    .global ptrvec
    .global num
    .global even
    
.section .text
    .global vec_sum_even
    
vec_sum_even:
    # prologue
    pushl %ebp # save previous stack frame pointer
    movl %esp, %ebp # the stack frame pointer for sum function
    pushl %ebx
    pushl %edi
    pushl %esi

    movl ptrvec, %ecx
    movl num, %edx

    movl $0, %ebx # contadoooo
    movl $0, %eax
   
loop:
    cmpl %edx, %ebx
    je end

    movl (%ecx), %esi
    movl %esi, even

    pushl %eax
    pushl %edx
    pushl %ecx
    
    call test_even
    movl %eax, %edi
    
    popl %ecx
    popl %edx
    popl %eax
    cmp $1, %edi
    jne zero
    addl (%ecx), %eax
    addl $4, %ecx
    incl %ebx
    jmp loop

zero:
    addl $4, %ecx
    incl %ebx
    jmp loop

end:
    # epilogue
    popl %esi
    popl %edi
    popl %ebx
    movl %ebp, %esp # restore the previous stack pointer ("clear" the stack)
    popl %ebp # restore the previous stack frame pointer
    ret
    