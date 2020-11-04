.section .data
.global i
.global j

.section .text

	.global fa
	
fa:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	
	movl i, %eax
	movl j, %ecx

	cmp %eax, %ecx
	je iguais
	addl %ecx, %eax
	addl $1, %eax
	jmp fim

iguais:
	subl %ecx, %eax
	addl $1, %eax

fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	





