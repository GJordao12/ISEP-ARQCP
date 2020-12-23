.section .data

.global fun1
.global fun2
.global fun3
.global fun4

.section .text

fun1:
# prologo
pushl %ebp
movl %esp, %ebp 

movl 8(%ebp), %edx # 1ºparametro: apontador para estrutura
movw (%edx), %ax # o 1ºelemento da estrutura é uma 2ºestrutura, logo é o primeiro elemento da 2ºestrutura
jmp end 


fun2:
# prologo
pushl %ebp
movl %esp, %ebp 

movl 8(%ebp), %edx # 1ºparametro: apontador para estrutura
addl $28, %edx # soma o offset para z para ir para o endereço onde este se encontra
movw (%edx), %ax # copia o valor de z para o ax
jmp end

fun3:
# prologo
pushl %ebp
movl %esp, %ebp 

movl 8(%ebp), %eax # 1ºparametro: apontador para estrutura
addl $28, %eax # soma o offset para z para ir para o endereço onde este se encontra. Devolve esse endereço
jmp end

fun4:
# prologo
pushl %ebp
movl %esp, %ebp 

movl 8(%ebp), %edx # 1ºparametro: apontador para estrutura
addl $8, %edx # soma o offset para chegar ao 2º elemento da estrutura, que é um apontador para outra estrutura
movl (%edx), %ecx # o apontado por edx é um apontador, entao copiamos esse apontador para o ecx
movw (%ecx), %ax # o apontado por ecx é o 1º elemento da estrutura apontada por edx
jmp end


end:
# epilogo
movl %ebp, %esp
popl %ebp
ret
