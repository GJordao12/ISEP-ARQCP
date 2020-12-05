.section .data

	x: 
	.int 0							
	
	num_elements_ptrdest:
	.int 0							
	
	.global num_elements_ptrdest	
	.global x						
	.global ptrsrc					
	.global ptrdest					
	.global num						
	
.section .text

	.global sort_without_reps		
	.global sort_array				
	.global exists_in_array			
	
sort_without_reps:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						
	pushl %esi						
	pushl %edi						
	
	movl $0, %edi					
	movl num, %esi					
	
	cmpl $0, %esi					
	je end							
	
	call sort_array					
	
	movl ptrsrc, %ecx				
	movl ptrdest, %edx				
	
	movl (%ecx), %ebx				
	movl %ebx, (%edx)				
	decl %esi						
	addl $1, %edi					
	addl $4, %ecx					
	addl $4, %edx					
	
next_int:
	cmpl $0, %esi					
	je end							
	
	movl (%ecx), %ebx				
	movl %ebx, x					
	movl %edi, num_elements_ptrdest	
	pushl %edx						
	pushl %ecx						
	call exists_in_array			
	popl %ecx						
	popl %edx						
	
	cmpl $1, %eax					
	je increment_and_next			
	movl (%ecx), %ebx				
	movl %ebx, (%edx)				
	decl %esi						
	addl $1, %edi					
	addl $4, %ecx					
	addl $4, %edx					
	jmp next_int					
	
increment_and_next:
	decl %esi						
	addl $4, %ecx					
	jmp next_int					
	
	end:
	movl %edi, %eax					
	popl %edi						
	popl %esi						
	popl %ebx						
	movl %ebp, %esp
	popl %ebp        
	ret
	
sort_array:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						
	pushl %esi						
	pushl %edi						
	
	movl ptrsrc, %ecx				
	movl ptrsrc, %edx				
	movl num, %edi					
	movl num, %eax					
	jmp sort						
	
decrease_num_elements:
	addl $4, %ecx					
	movl %ecx, %edx					
	decl %edi						
	cmpl $0, %edi					
	je end_sort_array				
	movl %edi, %eax					
	
sort:
	cmpl $0, %eax					
	je decrease_num_elements		 
	
	movl (%ecx), %ebx				
	movl (%edx), %esi				
	cmpl %ebx, %esi					
	jl swap_ints					
	decl %eax						
	addl $4, %edx					
	jmp sort						
	
swap_ints:
	movl %ebx, (%edx)				
	movl %esi, (%ecx)				
	decl %eax						
	addl $4, %edx					
	jmp sort						
	
end_sort_array:
	popl %edi						
	popl %esi						
	popl %ebx						
	movl %ebp, %esp
	popl %ebp        
	ret

exists_in_array:

	pushl %ebp
	movl %esp, %ebp
	pushl %ebx						
	pushl %esi						
	
	movl $0, %eax					
	movl x, %ecx					
	movl num_elements_ptrdest, %edx	
	movl ptrdest, %ebx				
	
check:	
	cmpl $0, %edx					
	je end_exists_in_array			
	
	movl (%ebx), %esi				
	cmpl %ecx, %esi					
	je x_exists						
	addl $4, %ebx					
	decl %edx						
	jmp check						
	
x_exists:
	movl $1, %eax					
	jmp end_exists_in_array			
	
end_exists_in_array:
	popl %esi						
	popl %ebx						
	movl %ebp, %esp
	popl %ebp        
	ret
