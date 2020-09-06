CC = gcc
LIBS = -Wall -lncurses
SRC = ./src
BIN = ./bin
LIST = $(BIN)/main.o $(BIN)/window.o

cursed-maze: $(BIN)/window.o $(SRC)/main.c
	$(CC) $(SRC)/main.c $(BIN)/window.o -o cursed-maze $(LIBS)
$(BIN)/window.o: $(SRC)/window.c
	$(CC) $(SRC)/window.c -c -o $(BIN)/window.o 
clean:
	rm -f bin/* && rm -f cursed-maze
