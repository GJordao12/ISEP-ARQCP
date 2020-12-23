.section .data
.section .text
.global fill_s2
fill_s2:
pushl %ebp
movl %esp, %ebp
pushl %ebx 
pushl %esi

movl 8(%ebp), %eax # apontador para a estrutura
movl 12(%ebp), %ebx # apontador para o vetor de 3 shorts w
movl $0, %esi # limpa esi (contador)
movl $0, %ecx # limpa ecx

loop_shorts:
cmpl $3, %esi # verifica se já guardou os três shorts
je inteiro # se sim, vai guardar o numero inteiro
movw (%ebx, %esi, 2), %cx # guarda o short no cx
movw %cx, (%eax) # coloca-o no w[] da estrutura 
addl $2, %eax # próximo short
incl %esi # aumenta contador
jmp loop_shorts

inteiro:
addl $2, %eax # adiciona 2 bytes por causa do alinhamento (existem 2 bytes entre o array de shorts e o inteiro)
movl 16(%ebp), %ecx # guarda o numero inteiro no ecx
movl %ecx, (%eax) # move-o para o j da estrutura
addl $4, %eax # adiciona 4 bytes (para passar para o próximo elemento da estrutura)
movl $0, %esi # limpa contador

movl 20(%ebp), %edx # apontador do vetor de 3 chars c

loop_chars:
cmpl $3, %esi # verifica se os 3 chars já foram preenchidos
je end # se sim, salta para o fim do programa
movb (%edx, %esi, 1), %cl # coloca o char no cl
movb %cl, (%eax) # guarda o valor do cl no vetor de chars da estrutura
addl $1, %eax # próximo char
incl %esi # aumenta contador
jmp loop_chars

end:
popl %esi 
popl %ebx
movl %ebp, %esp
popl %ebp
ret
