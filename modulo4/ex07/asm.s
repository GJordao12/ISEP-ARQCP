.section .data

.section .text

        .global count_even      # void count_even

count_even:

        # Prologue
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx

        movl 8(%ebp), %ecx
        movl 12(%ebp), %edx
        movl $0, %eax
        movl $0, %ebx
        

start:  
        cmp %ebx, %edx
        je fim

        testl $1, (%ecx)
        jz count

        addl $2, %ecx
        incl %ebx
        jmp start

count:
        incl %eax
        incl %ebx
        addl $2, %ecx
        jmp start
fim:        
        # Epilogue
        popl %ebx
        movl %ebp, %esp
        popl %ebp
        ret
