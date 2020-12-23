.section .data

.section .text

        .global prendas         # int prendas

prendas:

        # Prologue
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx
        pushl %esi
        pushl %edi

        movl 8(%ebp), %ecx      # move o apontador para ecx
        movl 12(%ebp), %edx     # move a quantidade de elementos do vetor
        movl $0, %ebx           # soma total de prendas

inicio:  
        cmp $0, %edx
        je fim

        movl (%ecx), %esi       # move o apontado do vetor para esi

        pushl %edx
        pushl %ecx
        pushl %ebx
        pushl %edi
        pushl %esi

        call result             # leva como parametro o esi

        cdq
        movl $4, %edi           # divide o return da funcao result por 4 para saber o numero de prendas individuais e deixa o resultado em eax
        divl %edi

        popl %esi
        popl %edi
        popl %ebx
        popl %ecx
        popl %edx

        addl %eax, %ebx         # soma a prenda individual ao total de prendas

        addl $4, %ecx           # proximo valor do vetor (adiciona 4 sendo que é um vetor de inteiros)
        decl %edx               # decrementa o contador de num passados como parametro
        jmp inicio

fim:        
        movl %ebx, %eax         # move o resultado para eax 

        # Epilogue
        popl %edi
        popl %esi
        popl %ebx
        movl %ebp, %esp
        popl %ebp
        ret
