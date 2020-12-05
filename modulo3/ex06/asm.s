.section .data
        .global ptr1        # char*

.section .text

        .global encrypt      # void

encrypt:

        # Prologue
        pushl %ebp
        movl %esp, %ebp

        movl ptr1, %ecx        # copia o valor de ptrvex para o registo %edx 
        movl $0 , %eax

start:
        cmpb $0, (%ecx)
	je end

	cmpb $32, (%ecx)
	je next_char

	cmpb $97, (%ecx)
	je next_char

	addb $2, (%ecx)
	jmp increment

next_char:
        incl %ecx

        jmp start

increment:
        incl %eax

        jmp next_char
end:
        movl %ebp, %esp
        popl %ebp
        ret
