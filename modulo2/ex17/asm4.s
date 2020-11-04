.section .data
	.global op1
	.global op2
	
.section .text

	.global divi
	
divi:
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl op1, %eax
	movl op2, %ecx

	cmp $0, %ecx
	je  se_for_zero # verifica se o denominador é zero

	cdq
	idivl %ecx
	adcl $0, %edx
	
	cmp $0, %eax # verifica se o numerador é zero
	je  se_for_zero
	jmp end

se_for_zero:
	movl $0, %eax
	jmp end

end:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret


