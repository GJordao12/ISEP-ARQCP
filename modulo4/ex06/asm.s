.section .text
	.global test_equal			
	
test_equal:

	# prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	pushl %esi

	movl 8(%ebp), %edx			
	movl 12(%ebp), %esi			
	movl $1, %eax				
	
loop:	
	movb (%edx), %bl			
	movb (%esi), %cl			
	
	cmpb $0, %bl				
	je checkLength				
	
	cmpb %bl, %cl				
	jne notEqual				
	addl $1, %edx				
	addl $1, %esi				
	jmp loop					
	
notEqual:
	movl $0, %eax				
	jmp fim					

checkLength:						
	cmpb $0, %cl				
	jne notEqual				
	jmp fim						
	
fim:	
	# epilogue
        popl %esi
	popl %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
