.section .data

.section .text

        .global greatest      # void greatest

greatest:

        # Prologue
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx

        movl 8(%ebp), %ebx
        movl 12(%ebp), %ecx
        movl 16(%ebp), %edx
        
        cmpl %ebx, %ecx
        jl maior

        cmpl %ecx, %edx
        jl outro

        movl %edx, %eax

        jmp fim

maior:
        cmpl %ebx, %edx
        jl maior2

        movl %edx, %eax

        jmp fim

outro: 
        movl %ecx, %eax

        jmp fim

maior2: 
        movl %ebx, %eax

        jmp fim
        
fim:        
        # Epilogue
        popl %ebx
        movl %ebp, %esp
        popl %ebp
        ret
