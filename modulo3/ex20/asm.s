.section .data

	v1: 
	.int 0						
	
	v2: 
	.int 0						
	
	v3: 
	.int 0						
	
	.global v1					
	.global v2					
	.global v3					
	.global ptrvec				
	.global num					
	
.section .text

	.global count_seq			
	.global generate_sequence	
	.global verify_condition	
	
count_seq:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx					
	
	movl $0, %ebx				
	movl ptrvec, %ecx			
	movl num, %edx				
	subl $2, %edx				
	
	check:
	
	cmpl $0, %edx				
	jle end						
	
	movl %ecx, ptrvec			
	pushl %ecx					
	pushl %edx					
	call generate_sequence		
	popl %edx					
	popl %ecx					
	
	pushl %ecx					
	pushl %edx					
	call verify_condition		
	popl %edx					
	popl %ecx					
	
	cmpl $1, %eax				
	je add_to_counter			
	addl $4, %ecx				
	decl %edx					
	jmp check					
	
	add_to_counter:
	addl $1, %ebx				
	addl $4, %ecx				
	decl %edx					
	jmp check					
	
	end:
	movl %ebx, %eax				
	popl %ebx					
	movl %ebp, %esp
	popl %ebp        
	ret
	
generate_sequence:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx					
	
	movl ptrvec, %ecx			
	
	movl (%ecx), %ebx			
	movl 4(%ecx), %eax			
	movl 8(%ecx), %edx			
	movl %ebx, v1				 
	movl %eax, v2				
	movl %edx, v3				
	
	popl %ebx					
	movl %ebp, %esp
	popl %ebp        
	ret

verify_condition:
	
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx					
	pushl %esi					
	pushl %edi					

	movl $0, %eax				
	movl v1, %edx				
	movl v2, %ecx				
	movl v3, %ebx				
	
	subl $1, %ecx				
	subl $2, %ebx				
	
	condition:
	
	cmpl %edx, %ecx				
	je first_is_true			
	jmp end_verify_condition	
	
	first_is_true:
	
	cmpl %edx, %ebx				
	je second_is_true			
	jmp end_verify_condition	
	
	second_is_true:
	
	movl $1, %eax				

	end_verify_condition:
	popl %edi					
	popl %esi					
	popl %ebx					
	movl %ebp, %esp
	popl %ebp        
	ret
