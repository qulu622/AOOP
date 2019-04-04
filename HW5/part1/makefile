all:Test

CC = g++
CFLAGS = -g -Wall -ansi

Test: DForm.o Form.o main.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

DForm.o: DForm.cpp
	$(CC) $(CFLAGS) -c $^

Form.o: Form.cpp
	$(CC) $(CFLAGS) -c $^

dep:
	$(CC) -M main.cpp Form.cpp DForm.cpp > depend

clean:
	rm *.o Test depend
