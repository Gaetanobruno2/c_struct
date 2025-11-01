CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = bst.o main.o
TARGET = main

default: all

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

bst.o: bst.c bst.h
main.o: main.c bst.h

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

