.section .data
	
	.global s
	
.section .text

	.global swapBytes
	
swapBytes:
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movw s, %ax
	movb %al, %cl
	movb %ah, %al
	movb %cl, %ah
		
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	