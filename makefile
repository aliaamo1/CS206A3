all: CS206A3

CS206A3: main.o list.o 
	gcc main.o list.o -o CS206A3

main.o: main.c
	gcc -c main.c

list.o: list.c
	gcc -c list.c

clean:
	rm *o CS206A3
