#MakeFile

# variaveis
INCLUDES = where_exists.h
SOURCES = main.c where_exists.c
OBJFILES = main.o where_exists.o
EXEC = ex16.out

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