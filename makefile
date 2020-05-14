CC = g++
INC = -Istring/include

SRC = ./src
STRING_MODULE_SRC = ./string/src

all: main

main: $(SRC)/main.cpp string.o
	$(CC) $(INC) -o main $(SRC)/main.cpp string.o
     
string.o: $(STRING_MODULE_SRC)/string.cpp
	$(CC) $(INC) -o string.o -c $(STRING_MODULE_SRC)/string.cpp

clean:
	rm main *.o
