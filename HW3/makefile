all:Complex

CC = g++
CFLAGS = -g -Wall -ansi

Complex: Complex.o main.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

Complex.o: Complex.cpp
	$(CC) $(CFLAGS) -c $^

dep:
	$(CC) -M main.cpp Complex.cpp > depend

clean:
	rm *.o Complex depend
