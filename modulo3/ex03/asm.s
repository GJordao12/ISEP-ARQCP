.section .data
        .global ptr1        # char*
        .global ptr2        # char*

.section .text

        .global str_copy_porto2    # void

str_copy_porto2:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl ptr1, %edx        # copia o valor de ptr1 para o registo %edx 
        movl ptr2, %ecx        # copia o valor de ptr2 para o registo %ecx

        start:
        movb (%edx), %al
        movb %al , (%ecx)

        cmpb $0, %al
        je end

        cmpb $'v', %al
        je v_occurence

        cmpb $'V', %al
        je v2_occurence

        jmp next_character

        v_occurence:
        movb $'b' , (%ecx) 
        jmp next_character

        v2_occurence:
        movb $'B' , (%ecx) 
        jmp next_character

        next_character:
        incl %edx
        incl %ecx

        jmp start

        end:
        
        movl %ebp, %esp
        popl %ebp
        ret
