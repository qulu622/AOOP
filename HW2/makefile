all:mytar

CC = g++
CFLAGS = -g -Wall -ansi

mytar: mytar.o main.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

mytar.o: mytar.cpp
	$(CC) $(CFLAGS) -c $^

dep:
	$(CC) -M main.cpp mytar.cpp > depend

clean:
	rm *.o mytar depend
