.section .data
        .global even        

.section .text

        .global test_even     

test_even:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl even, %eax
        movl $0, %edx
	movl $2, %ecx

start:
        cdq
	idivl %ecx
	cmpl $0, %edx
	je evenn
	movl $0, %eax 
	jmp end
	
evenn:
	movl $1, %eax

end:
        movl %ebp, %esp
        popl %ebp
        ret
