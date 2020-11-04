.section .data

	.global A
	.global B
	.global C
	.global D
	
.section .text

	.global compute
	
compute:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	# (A * B)
	movl A, %eax
	mull B
	
	# (A * B) + C
	movl C, %ecx
	addl %ecx, %eax

	# [(A * B) + C] \ D
	movl D, %ecx

	cmp $0, %ecx
	je  equal_zero # verifica se o denominador é zero

	cdq

	idivl %ecx

	adcl $0, %edx
	
	cmp $0, %eax # verifica se o numerador é zero
	je  equal_zero
	jmp fim

equal_zero:

	movl $0, %eax
	jmp fim

fim:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	

