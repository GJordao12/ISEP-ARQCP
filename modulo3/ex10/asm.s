.section .data
        .global ptr1 
        .global ptr2
        .global ptr3       

.section .text

        .global str_cat     

str_cat:

        # Prologue
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx

        movl ptr1, %ecx    
        movl ptr2, %edx
        movl ptr3, %eax

fristLoop:

        cmpb $0, (%ecx)
	je nextLoop

        movb (%ecx), %bl
        movb %bl, (%eax)
        incl %ecx
        incl %eax
        jmp fristLoop

nextLoop:
        cmpb $0, (%edx)
	je end

        movb (%edx), %bl
        movb %bl, (%eax)
        incl %edx
        incl %eax
        jmp nextLoop

end:    
        movb $0 , (%eax)
        popl %ebx
        movl %ebp, %esp
        popl %ebp
        ret
