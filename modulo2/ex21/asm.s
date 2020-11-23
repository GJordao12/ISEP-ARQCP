.section .data
.global code
.global currentSalary

.section .text

	.global new_salary
	
new_salary:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp

	movl $0, %eax
	movl $0, %ecx
	
	movl currentSalary, %eax
	movl code, %ecx

	cmp $10, %ecx
	je manager

	cmp $11, %ecx
	je engineer

	cmp $12, %ecx
	je technician

	jmp aumentoNormal

manager:

	addl $300, %eax
	jmp fim

engineer:

	addl $250, %eax
	jmp fim

technician:

	addl $150, %eax
	jmp fim

aumentoNormal:

	addl $100, %eax
	jmp fim

fim:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	




