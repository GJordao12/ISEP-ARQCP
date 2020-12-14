.section .data

.section .text

        .global inc_and_square      # void inc_and_square

inc_and_square:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl 8(%ebp), %ecx
        movl 12(%ebp), %eax
        
        addl $1, (%ecx)

        imull %eax
fim:        
        # Epilogue
        movl %ebp, %esp
        popl %ebp
        ret
