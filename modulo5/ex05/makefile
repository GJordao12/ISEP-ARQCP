INCLUDES = fill_student.h update_address.h
SOURCES = fill_student.c update_address.s main.c
OBJFILES = fill_student.o update_address.o main.o
EXEC = ex05

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