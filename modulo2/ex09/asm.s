.section .data
	.global A # 8 bits
	.global B # 16 bits
	.global C # 32 bits
	.global D # 32 bits
	
.section .text

	.global sum_and_subtract

sum_and_subtract:

	# prologue
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	
	movsxb A, %eax
	cdq # EDX:EAX
	movl %eax,%ebx
	movl %edx,%ecx
	
	movsxw B, %eax
	cdq # EDX:EAX
	addl %eax, %ebx
	adcl %edx, %ecx
	
	movl C, %eax
	cdq
	addl %eax, %ebx
	adcl %edx, %ecx
	
	movl D, %eax
	cdq
	subl %eax, %ebx
	sbbl %edx, %ecx

	movl %ebx, %eax
	movl %ecx, %edx
	
	
	# epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	