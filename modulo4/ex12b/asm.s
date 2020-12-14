.section .data
	
.section .text
	.global activate_bit			
	
activate_bit:
	#prologue
	pushl %ebp 			
	movl %esp, %ebp 
				
	pushl %ebx
	pushl %edi
	pushl %esi
		
	movl 8(%ebp), %esi				
	movb 12(%ebp), %cl				
									
	rorl %cl, (%esi)				
	movl (%esi), %ebx	    		
	orl $1, (%esi)			        
	roll %cl, (%esi)				

	andl $1, %ebx					
	cmpl $0, %ebx					
	je bitAlterado					
	movl $0, %eax					
	jmp fim							
									
bitAlterado:		
	movl $1, %eax					
	jmp fim						

fim:
	popl %esi
	popl %edi
	popl %ebx
	
	#epilogue
	movl %ebp, %esp
	popl %ebp        
	ret
