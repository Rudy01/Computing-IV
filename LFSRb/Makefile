CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(LFLAGS)

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	$(CC) -c PhotoMagic.cpp LFSR.hpp $(CFLAGS)

LFSR.o:	LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

clean:
	rm *.o
	rm PhotoMagic
	rm LFSR.hpp.gch
