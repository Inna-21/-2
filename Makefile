CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm

all: main

main: main.o
	$(CC) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main

