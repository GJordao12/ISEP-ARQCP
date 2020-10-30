ex11.out: main.o average.o
	gcc -g -Wall main.o average.o -o ex11.out

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

average.o: average.c
	gcc -g -Wall -c average.c -o average.o

run: ex11.out
	./ex11.out
