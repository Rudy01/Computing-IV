CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost = -lboost_unit_test_framework

all: GuitarHero GStest

GuitarHero: GuitarHero.o GuitarString.o RingBuffer.o
	$(CC) GuitarHero.o GuitarString.o RingBuffer.o -o GuitarHero $(SFLAGS)

GStest:	GStest.o GuitarString.o RingBuffer.o
	$(CC) GStest.o GuitarString.o RingBuffer.o -o GStest $(Boost)

GuitarHero.o: GuitarHero.cpp GuitarString.hpp
	$(CC) -c GuitarHero.cpp GuitarString.hpp $(CFLAGS)

GuitarString.o: GuitarString.cpp GuitarString.hpp
	$(CC) -c GuitarString.cpp GuitarString.hpp $(CFLAGS)

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) -c RingBuffer.cpp RingBuffer.hpp $(CFLAGS)

GStest.o: GStest.cpp
	$(CC) -c GStest.cpp $(Boost)

clean:
	rm *.o
	rm *.gch
	rm GuitarHero
	rm GStest
