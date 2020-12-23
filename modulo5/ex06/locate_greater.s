.section .data
.section .text
.global locate_greater
locate_greater:
pushl %ebp
movl %esp, %ebp
pushl %ebx # guarda ebx na stack
pushl %esi # guarda esi na stack
pushl %edi # guarda edi na stack

movl 8(%ebp), %ebx # guarda o primeiro parametro em ebx (apontador para a estrutura de aluno)
movl 12(%ebp), %ecx # guarda a nota minima no ecx
movl 16(%ebp), %edx # guarda o apontador do vetor de notas que são maiores que a nota mínima
addl $4, %ebx # move o apontador para o inicio do vetor de notas do aluno
movl $0, %esi # limpa esi
movl $0, %eax # limpa eax
movl $0, %edi # limpa edi

loop1:
cmpl $10, %esi # verifica se todas as notas foram verificadas
je end # se sim, salta para o fim do programa
movl (%ebx, %esi, 4), %edi # guarda a nota no edi
cmpl %ecx, %edi # verifica se é maior que o minimo
jg greater # se sim, salta para a linha "greater"
incl %esi # contador++
jmp loop1

greater:
incl %eax # nº de notas superiores à minima 
movl %edi, (%edx) # coloca a nota no vetor de notas superiores 
incl %esi # aumenta contador
addl $4, %edx # próxima posição do vetor de notas
jmp loop1

end:
popl %edi # retira edi da stack
popl %esi # retira esi da stack
popl %ebx # retira ebx da stack
movl %ebp, %esp
popl %ebp
ret
