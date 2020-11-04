.section .data
.global num

.section .text

	.global check_num
	
check_num:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	
	movl num, %eax 
	movl $2, %ecx

	cmp $0 , %eax # verifica se o numero é negativo
	jl e_negativo

	cdq
	idivl %ecx
	cmp $0, %edx
	je se_for_par
	movl $4, %eax
	jmp fim

se_for_par:
	movl $3, %eax 
	jmp fim

e_negativo:
	cdq
	idivl %ecx
	cmp $0, %edx
	je se_for_par_e_negativo 
	movl $2, %eax
	jmp fim

se_for_par_e_negativo:
	movl $1, %eax

fim:
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	




