CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic
SFLAGS = -lsfml-system

all: ED

ED: main.o ED.o
	$(CC) main.o ED.o -o ED $(SFLAGS)

main.o:	main.cpp ED.hpp
	$(CC) -c main.cpp ED.hpp $(CFLAGS)

ED.o:	ED.cpp ED.hpp
	$(CC) -c ED.cpp ED.hpp $(CFLAGS)

clean:
	rm *.o
	rm *.gch
	rm ED
