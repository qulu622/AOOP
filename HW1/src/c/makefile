all:main main2

CC = gcc

main: stack.o main.o
	$(CC) -o $@ $^

main2: stack.o main2.o
	$(CC) -o $@ $^

main.o: main.c
	$(CC) -c $^

main2.o: main2.c
	$(CC) -c $^

stack.o: stack.c
	$(CC) -c $^

dep:
	$(CC) -M main.c main2.c stack.c > depend

clean:
	rm *.o main main2 depend
