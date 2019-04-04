all:Test

CC = g++
CFLAGS = -g -Wall -ansi

Test: Trace.o Vector.o main.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

Trace.o: Trace.cpp
	$(CC) $(CFLAGS) -c $^

Vector.o: Vector.cpp
	$(CC) $(CFLAGS) -c $^

dep:
	$(CC) -M main.cpp Trace.cpp Vector.cpp > depend

clean:
	rm *.o Test depend
