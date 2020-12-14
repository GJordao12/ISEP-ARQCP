.section .data

.section .text

        .global cube      # void

cube:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl 8(%ebp), %eax
        imull  8(%ebp)
        imull  8(%ebp)
        
        movl %ebp, %esp
        popl %ebp
        ret
