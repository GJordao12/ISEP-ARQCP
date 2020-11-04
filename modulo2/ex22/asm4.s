.section .data
.global i
.global j

.section .text

	.global fa4
	
fa4:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	movl i, %eax
	movl j, %ecx
    addl %ecx, %eax

	cmp $10, %eax
	jl menor
    movl j, %eax
    movl j, %ebx
    cdq
    imull %ebx
    movl $3, %ebx
    idivl %ebx

menor:
    movl i, %eax
    movl i, %ebx
    cdq
    imull %ebx
    movl $4 , %ebx
    imull %ebx

fim:
	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	





