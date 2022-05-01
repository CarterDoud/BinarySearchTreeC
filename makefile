CC = gcc
CFLAGS = -Wall -g -std=c99

BIN = ./bin/
SRC = ./src/

program: $(BIN)main.o $(BIN)rule.o $(BIN)BinarySearchTreeAPI.o
	$(CC) $(CFLAGS) $(BIN)rule.o $(BIN)BinarySearchTreeAPI.o $(BIN)main.o -Iinclude -o $(BIN)program

test: $(BIN)testmain.o $(BIN)rule.o $(BIN)BinarySearchTreeAPI.o
	$(CC) $(CFLAGS) $(BIN)rule.o $(BIN)BinarySearchTreeAPI.o $(BIN)testmain.o -Iinclude -o $(BIN)testing
$(BIN)BinarySearchTreeAPI.o:$(SRC)BinarySearchTreeAPI.c
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)BinarySearchTreeAPI.c -o $(BIN)BinarySearchTreeAPI.o
$(BIN)rule.o:$(SRC)rule.c 
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)rule.c -o $(BIN)rule.o
$(BIN)testmain.o: $(SRC)testmain.c
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)testmain.c -o $(BIN)testmain.o
$(BIN)main.o: $(SRC)main.c
	$(CC) $(CFLAGS) -Iinclude -c $(SRC)main.c -o $(BIN)main.o
cls:
	clear

