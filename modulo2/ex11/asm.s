.section .data
	.global op1
	.global op2
	
.section .text

	.global test_flags
	
test_flags:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl op1, %eax
    movl op2, %ecx
    addl %ecx, %eax

	jc output_diff
	jo output_diff
	movl $0, %eax
	jmp final

output_diff:
	movl $1, %eax

final:

	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	