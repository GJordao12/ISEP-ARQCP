.section .data
.global byte1
.global byte2
	
.section .text

	.global concatBytes
	
concatBytes:
	# prologue
	
	pushl %ebp 
	movl %esp, %ebp
		
	movb byte2, %ah
    movb byte1, %al
    		
	#epilogue
	movl %ebp, %esp
	popl %ebp
	ret
	
	
	