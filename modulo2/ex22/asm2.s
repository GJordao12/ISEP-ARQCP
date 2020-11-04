.section .data
.global i
.global j

.section .text

	.global fa2
	
fa2:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	
	movl i, %eax
	movl j, %ecx

	cmp %ecx, %eax
	jg maior
	incl %ecx
	cdq
    imull %ecx
	jmp fim

maior:
	decl %eax
	cdq
    imull %ecx

fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	





