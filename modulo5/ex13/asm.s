.section .data

.global count_odd_matrix

.section .text

count_odd_matrix:
# prologo
pushl %ebp
movl %esp, %ebp 
# como usamos o ebx, esi e edi, damos push de todos
pushl %ebx
pushl %esi
pushl %edi

movl 8(%ebp), %edx # 1º parametro: apontador para matriz
movl 12(%ebp), %ecx # 2º: numero de linhas
movl 16(%ebp), %edi # 3º: numero de colunas
movl $0, %eax # inicia o contador resultado


looplines:
cmpl $0, %ecx # até acabarem as linhas
je end
movl (%edx), %ebx # vai buscar o endereço para a as colunas da 1º linha
jmp loopcolumn # começa o loop pela linha apontada por ebx

loopcolumn:
cmpl $0, %edi # até acabarem as colunas desta linha
je nextline # proxima linha

movl (%ebx), %esi # vai buscar o inteiro apontado por ebx (elemento da linha)
andl $1, %esi # vai buscar o bit menos significativo do inteiro
cmpl $1, %esi # se for 1 é impar, se nao é par
je oddnum

decl %edi # decrementa o numero de colunas da linha que faltam verificar
addl $4, %ebx # proximo elemento da linha (ou seja, proxima coluna)
jmp loopcolumn 

nextline:
movl 16(%ebp), %edi # reset ao numero de colunas
addl $4, %edx # proxima linha a verificar
decl %ecx # decrementa o numero de linhas que faltam verificar
jmp looplines # proxima verificaçao 

# se é impar, incrementa o contador resultado, decrementa o numero de colunas que faltam verificar 
# e passa para o proximo elemento da linha corrente
oddnum:
incl %eax
decl %edi
addl $4, %ebx
jmp loopcolumn


end:
# pop dos registos guardados no inicio da função
popl %edi
popl %esi
popl %ebx
# epilogo
movl %ebp, %esp
popl %ebp
ret
