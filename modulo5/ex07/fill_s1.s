.section .data

.global fill_s1

.section .text

fill_s1:
# prologo
pushl %ebp
movl %esp, %ebp 

movl 8(%ebp), %edx # 1º parametro: apontador para a estrutura

movl 12(%ebp), %eax # 2º parametro: novo i
movl %eax, (%edx) # copia o novo i para o primeiro elemento da estrutura (int i)
addl $4, %edx # proximo elemento da estrutura (+ 4 pois o primeiro é um inteiro)

movb 16(%ebp), %al # 3º parametro: novo c
movb %al, (%edx) # copia o novo c para o apontado por edx (2º elemento da estrutura)
addl $4, %edx # o proximo elemento da estrutura é um inteiro, logo tem de começar num address multiplo de 4, logo para alem do 1 byte que o char c
# ocupa, é preciso dar + 3 bytes de espaço

movl 20(%ebp), %eax # 4º parametro: novo j
movl %eax, (%edx) # copia o novo j para o apontado por edx (3ºelemento da estrutura)
addl $4, %edx # proximo elemento da estruta (+4 porque é um inteiro)

movb 24(%ebp), %al # 4º parametro: novo d
movb %al, (%edx) # copia novo d para o apontado por edx (4º elemento da estrutura)


# epilogo
movl %ebp, %esp
popl %ebp
ret
