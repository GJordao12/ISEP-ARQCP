# variaveis
INCLUDES = multiplication_table.h multiplication_table_n.h line.h
SOURCES = main.c multiplication_table.c multiplication_table_n.c line.c
OBJFILES = main.o multiplication_table.o multiplication_table_n.o line.o
EXEC = ex13.out

# Suffix rules
.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES}: ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}


