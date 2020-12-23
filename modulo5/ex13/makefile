INCLUDES = new_matrix.h asm.h
SOURCES = new_matrix.c asm.s main.c
OBJFILES = new_matrix.o asm.o main.o
EXEC = ex13

.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

.s.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES} : ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}