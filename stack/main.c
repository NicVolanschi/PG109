#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
  stack s = init();
  for(int i = 1; i < argc; i++)
    if(!strcmp(argv[i], "pop"))
      pop(s);
    else
      push(argv[i], s);

  printf("stack contains %d elements\n", size(s));
  printf("Element at top of the stack: %s\n", peek(s));
  printf("Elements: \n");

  // print stack data
  while(!isempty(s)) {
    printf("%s\n", pop(s));
  }

  printf("Stack full: %s\n" , isfull(s)?"true":"false");
  printf("Stack empty: %s\n" , isempty(s)?"true":"false");

  kill(s);
}
