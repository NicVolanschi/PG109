#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAXSIZE 8

struct queue_s {
  char * items[MAXSIZE];
  int front;
  int tail;
};

queue init() {
  queue s = malloc(sizeof(struct queue_s));
  s->front = 0;
  s->tail = 0;
  return s;
}

void kill(queue s) {
  free(s);
}

int isempty(queue s) {
  return size(s) == 0;
}

int isfull(queue s) {
  return size(s) == MAXSIZE - 1;
}

int size(queue s) {
  if (s->front >= s->tail)
    return s->front - s->tail;
  else
    return s->front - s->tail + MAXSIZE;
}

char * peek(queue s) {
  if(isempty(s)) {
    printf("peek: queue is empty.\n");
    exit(1);
  }
  return s->items[(s->front - 1) % MAXSIZE];
}

char * pop(queue s) {
  if(isempty(s)) {
    printf("pop: queue is empty.\n");
    exit(1);
  }
  char *res = s->items[s->tail];
  s->tail = (s->tail + 1) % MAXSIZE;
  return res;
}

void push(char * data, queue s) {
  if(isfull(s)) {
    printf("push: queue is full.\n");
    exit(1);
  }
  s->items[s->front] = data;
  s->front = (s->front + 1) % MAXSIZE;
}
