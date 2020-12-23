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
pushl %ebp
movl %esp, %ebp
pushl %ebx

movl 8(%ebp), %ebx
movl 12(%ebp), %edx
movl $0, %ecx

addl $offsetgrades, %ebx
myloop:
cmpl $10, %ecx
je end

movl (%edx, %ecx, 4), %eax
movl %eax, (%ebx)

addl $4, %ebx
incl %ecx
jmp myloop


end:
popl %ebx # pop ebx antigo
movl %ebp, %esp
popl %ebp
ret
