.section .data

	.global ptrvec
	.global num

.section .text

	.global vec_sum
	
vec_sum:
	# prologue
	
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	movl ptrvec, %ecx
	movl num, %edx
	movl $0, %ebx
	movl $0, %eax

sum:	
	cmp %edx, %ebx
	je fim

	addl (%ecx), %eax
	addl $4 , %ecx 

	incl %ebx

	jmp sum

fim:
	# epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	