CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic
Boost = -lboost_unit_test_framework

all: test RB

test: test.o RingBuffer.o
	$(CC) test.o RingBuffer.o -o test $(Boost)

RB: main.o RingBuffer.o
	$(CC) main.o RingBuffer.o -o RB

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) -c RingBuffer.cpp RingBuffer.hpp $(CFLAGS)

test.o: test.cpp RingBuffer.hpp
	$(CC) -c test.cpp RingBuffer.hpp $(CFLAGS)

main.o:	main.cpp RingBuffer.hpp
	$(CC) -c main.cpp RingBuffer.hpp $(CFLAGS)

clean:
	rm *.o
	rm *.gch
	rm test
	rm RB
