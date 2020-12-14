.section .data
	
.section .text

	.global count_bits_zero		
	
count_bits_zero:
	# prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx

	movl 8(%ebp), %ecx			    
	movl $0, %eax					
	movl $0, %ebx				
	
loop:
	cmpl $32, %ebx					
	je fim							
	
	addl $1, %ebx					
	sall %ecx						 
	jnc bitsZero	
				
	jmp loop						
	
bitsZero:
	addl $1, %eax					
	jmp loop						

fim:
	popl %ebx
	
	# epilogue
	movl %ebp, %esp
	popl %ebp        
	ret