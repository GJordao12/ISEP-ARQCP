.section .data
A:
	.int 0
B:
	.int 0
total:
	.int 0
.global i
.global A
.global B

.section .text

	.global somatorio
	
somatorio:
	
	# prologue
	pushl %ebp 
	movl %esp, %ebp
	pushl %ebx

	cmp $0, i # se o i < 1 não há somatório
	jl nao_executar
	je nao_executar

	movl $1, %ecx # vai ser utulizado como variavel de incrementação
	movl $1, %eax # guardar o primeiro i (o somatório começa com i=1) para os calculos

main:
	movl i, %ebx # guardar o valor fixo de i para comparar com %ecx que é a variavel de incrementação
	cmp %ebx, %ecx
	jl ciclo # enquanto %ecx nao for maior que o i chamar o ciclo
	je ciclo # enquanto %ecx nao for maior que o i chamar o ciclo
	jg guardar # quando %ecx for maior que o i para o ciclo e guardar o valor

ciclo:

	mull %ecx # i^2

	movl A, %ebx 
	mull %ebx # i^2 * A
	mull %ebx # i^2 * A^2

	movl B, %ebx
	divl %ebx # i^2 * A^2 / B

	incl %ecx # incrementar uma unidade 
	addl %eax, total # guardar o valor para cada i
	movl %ecx, %eax # guardar o proximo i para os calculos
	jmp main

guardar:
	movl total, %eax # guardar o resultado do somatório em %eax
	jmp fim

nao_executar:
	movl $0, %eax # se não houver somatório guardar 0 em %eax

fim:
	#epilogue
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret
	



