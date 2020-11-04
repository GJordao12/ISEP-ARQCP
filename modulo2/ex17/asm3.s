.section .data
	.global op1
	.global op2
	
.section .text

	.global mult
	
mult:
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl op1, %eax
	cmp $0, %eax
	je se_for_zero

	movl op2, %ecx
	cmp $0, %ecx
	je se_for_zero

	cdq
	mull %ecx
	adcl $0, %edx

	jmp fim

se_for_zero:
	movl $0, %eax
	jmp fim

fim:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret


