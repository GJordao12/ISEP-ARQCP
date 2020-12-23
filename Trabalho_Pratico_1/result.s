.section .data
# variaveis
tempo:
    .int 0 

proximidade:
    .int 0

.global tempo
.global proximidade

.section .text

    .global result
    
result:
    
    # prologue
    pushl %ebp 
    movl %esp, %ebp
    
    movl tempo, %eax
    cdq # eax parte baixa edx ficou a parte alta do número
    movl proximidade, %ecx 
    
    cmp $0, %eax # compara o valor do tempo com 0
    jle e_negativa # consideramos o valor inválido se o valor for menor ou igual a 0
    
    cmp $0, %ecx # compara o valor da proximidade com 0
    jle e_negativa # consideramos o valor inválido se o valor for menor ou igual a 0

    mull %ecx # o resultado ficará em edx:eax
    
    jmp fim # se ambos os valores forem válidos (positivos) então ele avança para o fim


e_negativa:
    # se um dos valores for inválido, retornamos 0
    movl $0, %eax
    movl $0, %edx

fim:
    # epilogue
    movl %ebp, %esp
    popl %ebp
    ret

