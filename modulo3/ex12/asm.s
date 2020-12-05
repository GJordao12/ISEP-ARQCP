.section .data

	.global ptrvec		
	.global num			
	
.section .text

	.global vec_zero	
	
vec_zero:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	
	movl $0, %eax		
	movl ptrvec, %ecx	
	movl num, %edx		
	
	check_short:
	
	cmpl $0, %edx		
	je end				
	
	cmpw $100, (%ecx)	
	jge put_to_zero		
	addl $2, %ecx		
	decl %edx			
	jmp check_short		
	
	put_to_zero:
	
	movw $0, (%ecx)		
	addl $2, %ecx		
	decl %edx			
	addl $1, %eax		
	jmp check_short		
	
	end:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
