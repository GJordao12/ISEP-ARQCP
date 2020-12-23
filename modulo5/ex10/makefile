INCLUDES = new_str.h
SOURCES = new_str.c main.c
OBJFILES = new_str.o main.o
EXEC = ex10

.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES} : ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}