#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXSIZE 8

struct stack_s {
  char * items[MAXSIZE];
  int top;
};

stack init() {
  stack s = malloc(sizeof(struct stack_s));
  s->top = -1;
  return s;
}

void kill(stack s) {
  free(s);
}

int isempty(stack s) {
  return size(s) == 0;
}

int isfull(stack s) {
  return size(s) == MAXSIZE;
}

int size(stack s) {
  return s->top + 1;
}

char * peek(stack s) {
  if(isempty(s)) {
    printf("peek: stack is empty.\n");
    exit(1);
  }
  return s->items[s->top];
}

char * pop(stack s) {
  if(isempty(s)) {
    printf("pop: stack is empty.\n");
    exit(1);
  }
  return s->items[s->top--];;
}

void push(char * data, stack s) {
  if(isfull(s)) {
    printf("push: stack is full.\n");
    exit(1);
  }
  s->items[++s->top] = data;
}
