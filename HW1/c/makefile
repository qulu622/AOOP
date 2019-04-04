all:main main2

CC = gcc
CFLAGS = -g -Wall -ansi

main: stack.o main.o
	$(CC) -o $@ $^

main2: stack.o main2.o
	$(CC) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $^

main2.o: main2.c
	$(CC) $(CFLAGS) -c $^

stack.o: stack.c
	$(CC) $(CFLAGS) -c $^

dep:
	$(CC) -M main.c main2.c stack.c > depend

clean:
	rm *.o main main2 depend
