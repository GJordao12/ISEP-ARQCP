INCLUDES = sizes.h 
SOURCES = sizes.c main.c
OBJFILES = sizes.o main.o
EXEC = ex01

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