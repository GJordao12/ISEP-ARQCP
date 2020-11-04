.section .data
.global num
	
.section .text

	.global steps
	
steps:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	movl num, %ecx
	movl num, %eax
	cdq
	movl $3, %ebx
	mull %ebx # Multiplies by 3

	addl $6, %eax # Adds 6

	cdq
	divl %ebx # Divides by 3

	addl $12, %eax #  Adds 12

	subl %ecx, %eax	# Subtracts num

	subl $1, %eax # Subtracts 1

	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	


