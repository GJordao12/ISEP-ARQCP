.section .data
	.global op1
	.global op2
	
.section .text

	.global subt

subt:
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl op1, %eax
	movl op2, %ecx

	subl %ecx, %eax
	

	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret

