.section .data

sum:
        .int 0
product:
        .int 0

.section .text

        .global calculate      # void calculate

calculate:

        # Prologue
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx

        movl sum, %eax # soma esta no eax
        movl product, %ebx # produto esta no ebx
        movl 8(%ebp), %ecx # 1º parametro no ecx
        movl 12(%ebp), %edx # 2º parametro no edx

        # soma
        movl %ecx, %eax
        addl %edx, %eax
        movl %eax, sum

        # produto
        movl %ecx, %ebx
        imull %edx, %ebx
        movl %ebx, product

        movl $'+', %eax

        # 1º call da funcao print (soma)
        pushl product
        pushl sum
        pushl %edx
        pushl %ecx
        pushl %eax

        call print_result

        popl %eax
        popl %ecx
        popl %edx
        popl sum
        popl product
        
        # 2º call da funcao print (produto)
        movl $'*', %eax

        pushl sum
        pushl product
        pushl %edx
        pushl %ecx
        pushl %eax

        call print_result

        popl %eax
        popl %ecx
        popl %edx
        popl product
        popl sum

        movl sum, %eax
        subl product, %eax

        # Epilogue
        popl %ebx
        movl %ebp, %esp
        popl %ebp
        ret
