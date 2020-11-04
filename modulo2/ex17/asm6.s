.section .data
	.global op1
	
.section .text

	.global pot2
	
pot2:
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl op1, %eax
	imull op1, %eax

	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret


