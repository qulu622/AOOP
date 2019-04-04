all:main main2

CC = g++
CFLAGS = -g -Wall -ansi

main: stack.o main.o
	$(CC) -o $@ $^

main2: stack.o main2.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

main2.o: main2.cpp
	$(CC) $(CFLAGS) -c $^

stack.o: stack.cpp
	$(CC) $(CFLAGS) -c $^

dep:
	$(CC) -M main.cpp main2.cpp stack.cpp > depend

clean:
	rm *.o main main2 depend
