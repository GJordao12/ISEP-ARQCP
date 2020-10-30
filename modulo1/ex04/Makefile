#MakeFile

# variaveis
INCLUDES = upper1.h
SOURCES = main.c upper1.c
OBJFILES = main.o upper1.o
EXEC = ex04.out

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