CC = gcc -Wall
LIBS = -lncurses
SRC = ./src
BIN = ./bin
LIST = $(BIN)/main.o $(BIN)/window.o $(BIN)/entity.o

cursed-maze: $(LIST)
	$(CC) $(LIST) -o cursed-maze $(LIBS)
$(BIN)/%.o: $(SRC)/%.c
	$(CC) $< -c -o $@
clean:
	rm -f bin/* && rm -f cursed-maze
