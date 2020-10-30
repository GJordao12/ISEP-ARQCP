.section .data
.global A
.global B
	
.section .text

	.global isMultiple
	
isMultiple:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	cmp $0, B
	je se_for_zero
	jl e_negativo
	
	cmp $0, A
	jl e_negativo

	movl A, %eax
	cdq
	idivl B

	cmp $0, %edx
	je e_multiplo

	movl $0, %eax
	jmp fim

se_for_zero:
	movl $0, %eax
	jmp fim

e_multiplo:
	movl $1, %eax
	jmp fim

e_negativo:
	movl $0, %eax

fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	
