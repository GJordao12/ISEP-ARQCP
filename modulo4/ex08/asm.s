.section .data
	
.section .text

	.global calc			
	
calc:
	# prologue
	pushl %ebp    
	movl %esp, %ebp 
	
	pushl %ebx
	pushl %esi
	pushl %edi

	movl 8(%ebp), %edi			
	movl 12(%ebp), %esi			
	movl 16(%ebp), %ebx			
	
	movl (%esi), %eax			
	subl %edi, %eax				
	mull %ebx					
	subl $2, %eax				
		
fim:	
	# epilogue
	popl %edi
	popl %esi
	popl %ebx
	movl %ebp, %esp
	popl %ebp        
	ret
