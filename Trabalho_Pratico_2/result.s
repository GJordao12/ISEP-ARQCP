.section .data

.section .text

        .global result                  # int result

result:

        # Prologue
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx

        movl 8(%ebp), %ecx              # parametro da funcao para ecx
        movl $0, %edx                   # inicializa contador de bits
        movl $0, %eax                   # inicializa peso total

inicio:
        cmp $32, %edx
        je fim
        sall %ecx                       # shift para a esquerda 
        jc bitsAtivos                   # se for um bit ativo ou seja 1 vai para bits ativos
        incl %edx
        jmp inicio
    
bitsAtivos:

        movl %edx, %ebx                 # move o contador para ebx

        shr %ebx                        # realiza shift para a direita
        jc par                          # verifica o carry da operacao anterior

        decl %eax                       # decrementa o peso
        incl %edx                       # incrementa o contador de bits
        jmp inicio

par:                                   
        incl %eax                       # incrementa o peso 
        incl %edx                       # incrementa o contador de bits
        jmp inicio

colocarZero:

        movl $0, %eax                   # move 0 para eax se o peso for negativo
        jmp fim
fim:    
        cmp $0, %eax                    # veriffica se o peso é negativo
        jl colocarZero

        # Epilogue
        popl %ebx
        movl %ebp, %esp
        popl %ebp
        ret
