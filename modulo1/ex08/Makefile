#MakeFile

# variaveis
INCLUDES = array_sort2.h
SOURCES = main.c array_sort2.c
OBJFILES = main.o array_sort2.o
EXEC = ex08.out

# Suffix rules
.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean: 
	rm -f *.o ${EXEC}