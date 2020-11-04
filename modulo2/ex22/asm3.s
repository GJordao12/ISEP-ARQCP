.section .data
.global i
.global j

.section .text

	.global fa3
	
fa3:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	movl i, %eax
	movl j, %ecx

	cmp %ecx, %eax
	jg if
	je if
	incl %ecx
    imull %ecx
	movl %ecx, %eax # h
	movl %eax, %ebx
	addl %ecx, %ebx
	addl $2, %ebx # g 
	movl %eax, %edx
	movl %ebx, %eax
	movl %edx, %ebx
	cdq
	idivl %ebx
	jmp fim

if:
	cdq
    imull %ecx # h
	movl i, %ebx
	addl $1, %ebx # g
	movl %eax, %edx
	movl %ebx, %eax
	movl %edx, %ebx
	cdq
	idivl %ebx

fim:
	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	





