.section .data

.section .text
.global approved_semester
approved_semester:
pushl %ebp
movl %esp, %ebp
pushl %ebx

movl 8(%ebp), %ebx # vai buscar o parametro da função: apontador para a estrutura
movl (%ebx), %ecx # vai buscar o n_students (nº de alunos = nº de elementos do vetor de notas), que estão nos primeiros 4 bytes da estrutura
addl $4, %ebx # adiciona 4 para chegar ao apontador do vetor de notas
movl (%ebx), %edx # coloca o apontador do vetor em edx
movl $0, %eax # limpa eax: vai contar quantos alunos foram aprovados

loop_students:
cmpl $0, %ecx # verifica se todos os alunos já foram verificados
je end # se sim, salta para o fim do programa
pushl %eax # guarda eax na stack (contador de alunos)
pushl %ecx # guarda ecx na stack (nº de estudantes)
pushl %ebx # guarda ebx na stack (apontador para a estrutura)
pushl %edx # guarda edx na stack (apontador para o vetor de notas). Este é o parâmetro para a função approved_student
call approved_student # chama a função que verifica se o aluno foi aprovado
popl %edx # retira edx antigo da stack
popl %ebx # retira ebx antigo da stack
popl %ecx # retira ecx antigo da stack
cmpl $1, %eax # verifica se o aluno foi aprovado: a função approved_student retorna 1 se o aluno foi aprovado e 0 quando reprovado
je approved # se for 1, foi aprovado e salta para a linha "approved"
addl $1, %edx # próximo aluno/nota
popl %eax # retira eax antigo da stack
decl %ecx # diminui o nº de estudantes verificado
jmp loop_students

approved: # quando aluno é aprovado
popl %eax # retira eax da stack
incl %eax # aumenta o nº de alunos aprovados
decl %ecx # diminui o nº de alunos por verificar
addl $1, %edx # próximo aluno/nota
jmp loop_students

end: # retorna eax
popl %ebx
movl %ebp, %esp
popl %ebp
ret

# ####################################################################### #
approved_student:
pushl %ebp
movl %esp, %ebp
pushl %ebx # guarda ebx
pushl %esi # guarda esi

movl $0, %ebx # limpa ebx
movb $0, %cl # limpa cl (vai ser o contador)
movl 8(%ebp), %edx # vai buscar o parâmetro à stack: apontador para a nota do aluno a verificar
movb (%edx), %bl # coloca a nota no bl
movb $1, %al # cria a mask
movl $0, %esi # limpa esi (nº de módulos aprovados)

loop_grades:
cmpb $8, %cl # verifica se todos os módulos foram verificados: 1 char = 1 byte = 8 bits = 8 módulos 
je check_if_approved # se sim, então salta para check_if_approved e verifica quantos módulos foi aprovado
shrb %cl, %bl # faz cl (posição do bit que estamos a tratar) shifts para a direita da nota 
andb %al, %bl # and 1 com bit mais o bit menos significativo de bl (devido aos shifts). Guarda o resultado em bl
cmpb $1, %bl # se bl = 1, então quer dizer que foi aprovado (and 1, 1 = 1), se bl = 0, não foi aprovado (and 1, 0 = 0)
je module_approved # se bl = 1, então foi aprovado ao módulo e salta para module_approved
movb (%edx), %bl # restaura o valor de bl (coloca o inicial)
incb %cl # aumenta o nº de módulos verificados
jmp loop_grades

module_approved: # quando é aprovado ao módulo
incl %esi # aumenta o nº de módulos aprovado
incb %cl # aumenta o nº de módulos verificados
movb (%edx), %bl # restaura o valor de bl (coloca o inicial)
jmp loop_grades

check_if_approved: # no final, quando todos os módulos/bits são verificados
cmpl $5, %esi # verifica se o nº de módulos aprovados (guardado em esi) é maior ou igual a 5
jge student_approved # se sim, o aluno foi aprovado e salta para student_approved
movl $0, %eax # se não foi aprovado (condição não se verifica), então coloca 0 no eax e retorna-o
jmp end_approved # fim do função

student_approved: # quando aluno é aprovado
movl $1, %eax # coloca 1 no eax e retorna-o
jmp end_approved # fim da função

end_approved: # fim da função
popl %esi # restaura esi
popl %ebx # restaura ebx
movl %ebp, %esp
popl %ebp
ret
