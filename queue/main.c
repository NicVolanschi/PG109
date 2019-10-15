#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(int argc, char *argv[]) {
  queue q = init();
  for(int i = 1; i < argc; i++)
    if(!strcmp(argv[i], "pop"))
      pop(q);
    else
      push(argv[i], q);

  printf("queue contains %d elements\n", size(q));
  printf("Element at top of the queue: %s\n", peek(q));
  printf("Elements: \n");

  // print queue data
  while(!isempty(q)) {
    printf("%s\n", pop(q));
  }

  printf("queue full: %s\n" , isfull(q)?"true":"false");
  printf("queue empty: %s\n" , isempty(q)?"true":"false");

  kill(q);
}
