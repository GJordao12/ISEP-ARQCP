# Makefile

# Variáveis:
INCLUDES = asm.h
SOURCES = asm.s main.c
OBJFILES = asm.o main.o
EXEC = main

#Suffix rules
.SUFFIXES : .c .o

.c.o: 
	gcc -m32 -Wall -g -c $<
	
.SUFFIXES : .s .o	
	
.s.o:
	gcc -m32 -Wall -g -c $<
	
${EXEC}: ${OBJFILES}
	gcc -m32 -Wall -g -o ${EXEC} ${OBJFILES}
	
${OBJFILES}: ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}
	
clean: 
	rm -f ${OBJFILES} ${EXEC}

