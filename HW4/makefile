all:getToken

CC = g++
CFLAGS = -g -Wall -ansi
OBJSc = lexer.cpp num.cpp real.cpp tag.cpp token.cpp type.cpp word.cpp main.cpp
OBJSo = lexer.o num.o real.o tag.o token.o type.o word.o main.o

getToken: ${OBJSo}
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

lexer.o: lexer.cpp
	$(CC) $(CFLAGS) -c $^

num.o: num.cpp
	$(CC) $(CFLAGS) -c $^

real.o: real.cpp
	$(CC) $(CFLAGS) -c $^

tag.o: tag.cpp
	$(CC) $(CFLAGS) -c $^

token.o: token.cpp
	$(CC) $(CFLAGS) -c $^

type.o: type.cpp
	$(CC) $(CFLAGS) -c $^

word.o: word.cpp
	$(CC) $(CFLAGS) -c $^

i1: 
	./getToken < test1.txt > o1

i2: 
	./getToken < test2.txt > o2

dep:
	$(CC) -M ${OBJSc} > depend

clean:
	rm *.o getToken o1 o2 depend
