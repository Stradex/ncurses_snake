CC = gcc
CFLAGS = -lncurses -I./include/
SOURCES = ./src/*.c

all: compile run clean

compile: 
	$(CC) $(SOURCES) $(CFLAGS) -o snake

run:
	./snake

clean:
	rm snake
