#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAXSIZE 8

struct cell_s {
  char * data;
  struct cell_s *next;
};

struct queue_s {
  int length;
  struct cell_s *front;
  struct cell_s *tail;
};

queue init() {
  queue s = malloc(sizeof(struct queue_s));
  s->front = NULL;
  s->tail = NULL;
  s->length = 0;
  return s;
}

void kill(queue s) {
  struct cell_s *c = s->front;
  while (c != NULL) {
    free(c);
    c = c->next;
  }
  free(s);
}

int isempty(queue s) {
  return size(s) == 0;
}

int isfull(queue s) {
  return 0;
}

int size(queue s) {
  return s->length;
}

char *peek(queue s) {
  if(isempty(s)) {
    printf("peek: queue is empty.\n");
    exit(1);
  }
  return s->front->data;
}

char *pop(queue s) {
  if(isempty(s)) {
    printf("pop: queue is empty.\n");
    exit(1);
  }
  char *res = s->front->data;
  struct cell_s *old = s->front;
  s->front = s->front->next;
  free(old);
  s->length--;
  return res;
}

void push(char *data, queue s) {
  struct cell_s *new = malloc(sizeof(struct cell_s));
  new->data = data;
  new->next = NULL;
  if (s->tail == NULL) {
    s->front = s->tail = new;
    s->length = 1;
  } else {
    s->tail->next = new;
    s->tail = new;
    s->length++;
  }
}
