# Makefile
CC=gcc
CFLAGS=-Wall -std=c99
OBJS=stack.o main.o

stack: $(OBJS)
	$(CC) -o $@ $^
stack.o: stack.c stack.h
	$(CC) -c $(CFLAGS) $<
main.o: main.c stack.h
	$(CC) -c $(CFLAGS) $<
clean:
	rm -f $(OBJS) stack
