INCLUDES = new_matrix.h fill_matrix.h add_matrixes.h
SOURCES = new_matrix.c fill_matrix.c add_matrixes.c main.c
OBJFILES = new_matrix.o fill_matrix.o add_matrixes.o main.o
EXEC = ex14

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