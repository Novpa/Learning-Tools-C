all: program run

program: main.o function.o
	gcc -o program main.o function.o

main.o: main.c
	gcc -c main.c

function.o: function.c
	gcc -c function.c

run: program
	./program

clean:
	rm -f *.o program