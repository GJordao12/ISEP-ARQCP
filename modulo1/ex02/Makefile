#MakeFile

# variaveis
INCLUDES = print_array.h copy_vec.h
SOURCES = main.c copy_vec.c print_array.c
OBJFILES = main.o copy_vec.o print_array.o
EXEC = ex02.out

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
