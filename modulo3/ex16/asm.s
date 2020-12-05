.section .data

	.global ptr1		
	.global ptr2		
	.global num			
	
.section .text

	.global swap		
	
swap:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx			
	
	movl ptr1, %ecx		
	movl ptr2, %edx		
	movl num, %eax		
	
copy:
	
	cmpl $0, %eax		
	je end				
	
	movb (%ecx), %bl	
	movb (%edx), %bh	
	movb %bl, (%edx)	
	movb %bh, (%ecx)	
	decl %eax			
	incl %ecx			
	incl %edx			
	jmp copy			

end:
	#epilogue
	popl %ebx			
	movl %ebp, %esp
	popl %ebp        
	ret
