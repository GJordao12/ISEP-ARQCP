INCLUDES = approved_semester.h fill_group.h
SOURCES = approved_semester.s fill_group.c main.c
OBJFILES = approved_semester.o fill_group.o main.o
EXEC = ex16

.SUFFIXES : .c .o

.c.o:
	gcc -Wall -g -c $<

.s.o:
	gcc -Wall -g -c $<

${EXEC}: ${OBJFILES}
	gcc -Wall -g -o ${EXEC} ${OBJFILES}

${OBJFILES} : ${SOURCES} ${INCLUDES}

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${OBJFILES} ${EXEC}