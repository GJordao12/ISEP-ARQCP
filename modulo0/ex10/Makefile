ex10.out: main.o average.o
	gcc -g -Wall main.o average.o -o ex10.out

main.o: main.c
	gcc -g -Wall -c main.c -o main.o

average.o: average.c
	gcc -g -Wall -c average.c -o average.o

run: ex10.out
	./ex10.out
