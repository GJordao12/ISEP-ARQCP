.section .data
base:
		.int 0
height:
		.int 0
.global base
.global height
	
.section .text

	.global getArea
	
getArea:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl base, %eax
	mull height

	cmp $0, %eax
	je se_for_zero

	movl $2, %ecx
	divl %ecx
	jmp fim
	
se_for_zero:
	movl $0 , %eax

fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	


