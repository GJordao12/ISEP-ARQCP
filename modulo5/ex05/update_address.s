.section .data
.equ offset, 124 # número de bytes que tem de avançar para chegar ao início do vetor char [] address
.equ offsetgrades, 4 # número de bytes que tem de avançar para chegar ao início do vetor int [] grades
.section .text
.global update_address
.global update_grades
update_address:
pushl %ebp
movl %esp, %ebp
pushl %ebx # guarda ebx 

movl 8(%ebp), %eax # obtem o primeiro parametro (apontador para a estrutura a modificar) e guarda-o em eax
movl 12(%ebp), %ebx # obtem o segundo parametro (apontador para a nova address) e guarda em ebx

addl $offset, %eax # move o apontador para o inicio do vetor da address
loop1:
cmpl $0, (%ebx) # verifica se a nova address já acabou
je end # se sim, salta para o fim
movb (%ebx), %cl # move o novo char para o cl
movb %cl, (%eax) # move o char em cl para o apontado por eax (substitui a address antiga)
addl $1, %eax # incrementa o apontador da address antiga (proximo char)
addl $1, %ebx # incrementa o apontador da address nova (proximo char)
jmp loop1

update_grades:
# prologo 
pushl %ebp
movl %esp, %ebp
pushl %ebx # como usamos os ebx, damos push no inicio

movl 8(%ebp), %ebx # primeiro parametro que é o endereço do student
movl 12(%ebp), %edx # segundo parametro que é o apontador para as novas notas 
movl $0, %ecx # iniciamos o indice a 0

addl $offsetgrades, %ebx # acrescentamos o offset de notas ao inicial de student para obtermos o endereço inicial do vetor de notas do student
myloop:
cmpl $10, %ecx # acabou o loop?
je end # salta para o fim/epilogo

movl (%edx, %ecx, 4), %eax # Copia o valor em grades[ecx] para o eax
movl %eax, (%ebx) # copia o valor de eax para o vetor de grades do student

addl $4, %ebx # proximo inteiro do vetor de grades do student
incl %ecx # incrementa o indice
jmp myloop # proxima iteraçao


end:
popl %ebx # pop ebx antigo
movl %ebp, %esp
popl %ebp
ret
