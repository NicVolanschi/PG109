# Makefile
CC=gcc
CFLAGS=-Wall -std=c99
OBJS=queue.o main.o

queue: $(OBJS)
	$(CC) -o $@ $^
queue.o: queue.c queue.h
	$(CC) -c $(CFLAGS) $<
main.o: main.c queue.h
	$(CC) -c $(CFLAGS) $<
clean:
	rm -f $(OBJS) queue
