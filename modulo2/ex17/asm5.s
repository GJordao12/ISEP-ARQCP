.section .data
	.global op1
	
.section .text

	.global mod
	
mod:
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl op1, %eax

	cmp $0, %eax
	jl  se_for_negativo # verifica se o número dentro do módulo é negativo

	jmp end

se_for_negativo:
	imull $-1, %eax
	jmp end

end:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret


