CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
OBJS = main.o lista.o estrategia1.o estrategia2.o estrategia3.o

all: tp3

tp3: $(OBJS)
	$(CC) $(CFLAGS) -o tp3 $(OBJS)

main.o: main.c lista.h estrategia1.h estrategia2.h estrategia3.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

estrategia1.o: estrategia1.c estrategia1.h lista.h
	$(CC) $(CFLAGS) -c estrategia1.c

estrategia2.o: estrategia2.c estrategia2.h lista.h
	$(CC) $(CFLAGS) -c estrategia2.c

estrategia3.o: estrategia3.c estrategia3.h lista.h
	$(CC) $(CFLAGS) -c estrategia3.c

clean:
	rm -f tp3 $(OBJS)
