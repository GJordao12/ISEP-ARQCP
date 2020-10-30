#MakeFile

# variaveis
INCLUDES = compress_shorts.h 
SOURCES = main.c compress_shorts.c 
OBJFILES = main.o compress_shorts.o 
EXEC = ex18.out

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