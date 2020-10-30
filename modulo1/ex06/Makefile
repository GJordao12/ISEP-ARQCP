#MakeFile

# variaveis
INCLUDES = power_ref.h
SOURCES = main.c power_ref.c
OBJFILES = main.o power_ref.o
EXEC = ex06.out

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