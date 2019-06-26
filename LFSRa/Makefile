CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
LFLAGS = -lboost_unit_test_framework

all: LFSR test

test: test.o LFSR.o
	$(CC) test.o LFSR.o -o test $(LFLAGS)

test.o:	test.cpp LFSR.hpp
	$(CC) -c test.cpp LFSR.hpp $(CFLAGS)

LFSR: main.o LFSR.o
	$(CC) main.o LFSR.o -o LFSR

main.o:	main.cpp LFSR.hpp
	$(CC) -c main.cpp $(CFLAGS)

LFSR.o:	LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

clean:
	rm test
	rm LFSR
	rm *.o
	rm LFSR.hpp.gch
