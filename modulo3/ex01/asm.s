.section .data
.global ptr1
.global frase
	
.section .text

	.global zero_count
	
zero_count:
	# prologue
	
	pushl %ebp 
	movl %esp, %ebp


	movl ptr1,%ecx
	movl $0, %eax

my_loop:
	
	movb (%ecx), %dl
	
	cmpb $0, %dl
	je fim
	
	cmpb $48, %dl
	je soma
	
	incl %ecx

	jmp my_loop

 soma: 
	
	addl $1, %eax
	incl %ecx
	jmp my_loop

fim:
	# epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	
	
	