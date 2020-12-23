INCLUDES = new_matrix.h find_matrix.h fill_matrix.h
SOURCES = new_matrix.c find_matrix.c fill_matrix.c main.c
OBJFILES = new_matrix.o find_matrix.o fill_matrix.o main.o
EXEC = ex12

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