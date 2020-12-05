.section .data

	.global ptrvec			
	.global x				
	.global num				
	
.section .text

	.global exists			
	.global vec_diff		
	
exists:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx				
	pushl %esi				
	
	movl $0, %eax			
	movl $0, %esi			
	movl ptrvec, %edx		
	movl num, %ecx			
	movw x, %bx				
	
checks:
	
	cmpl $2, %esi			
	je has_duplicates		
	
	cmpl $0, %ecx			
	je end					
	
	cmpw (%edx), %bx		
	jne next_short			
	addl $1, %esi			
	
next_short:
	addl $2, %edx			
	decl %ecx				
	jmp checks				
	
has_duplicates:
	movl $1, %eax			
	
end:
	# epilogue
	popl %esi				
	popl %ebx				
	movl %ebp, %esp
	popl %ebp
	ret
	
vec_diff:

	#prologue
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx				
	
	movl $0, %ebx			
	movl ptrvec, %edx		
	movl num, %ecx			
	
checks_elements:
	
	cmpl $0, %ecx			
	je end_vec_diff			
	
	movw (%edx), %ax		
	movw %ax, x				
	pushl %edx				
	pushl %ecx				
	call exists				
	popl %ecx				
	popl %edx				
	
	cmpl $0, %eax			
	je no_duplicates_sum	
	addl $2, %edx			
	decl %ecx				
	jmp checks_elements		
	
no_duplicates_sum:
	addl $1, %ebx			
	addl $2, %edx			
	decl %ecx				
	jmp checks_elements		
	
end_vec_diff:
	movl %ebx, %eax			
	# epilogue
	popl %ebx				
	movl %ebp, %esp
	popl %ebp
	ret
