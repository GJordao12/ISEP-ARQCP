#MakeFile

# variaveis
INCLUDES = odd_sum.h
SOURCES = main.c odd_sum.c
OBJFILES = main.o odd_sum.o
EXEC = ex10.out

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