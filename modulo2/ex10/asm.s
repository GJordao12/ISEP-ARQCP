.section .data
.global op1
.global op2
	
.section .text

	.global sum2ints
	
sum2ints:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	movl op1, %eax
    cdq # eax parte baixa edx ficou a parte alta do número
    movl %eax , %ebx
    movl %edx, %ecx

    movl op2, %eax
    cdq # eax parte baixa edx ficou a parte alta do número
    addl %ebx, %eax
	adcl %ecx, %edx

	#epilogue
    popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	