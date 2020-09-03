CC = gcc
LIBS = -Wall -lncurses
SRC = ./src
BIN = ./bin
LIST = $(BIN)/main

all: $(LIST)

$(BIN)/%: $(SRC)/%.c
	 $(CC) $(LIBS) $< -o $@
