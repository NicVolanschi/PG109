#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int i;
  char *shortest;
  char *longest;
  if(argc == 1) {
    printf("usage: %s string ...\n", argv[0]);
    return 1;
  }
  shortest = argv[1];
  longest = argv[1];
  for(i = 2; i < argc; i = i + 1) {
    if(strlen(argv[i]) < strlen(shortest))
      shortest = argv[i];
    if(strlen(argv[i]) > strlen(longest))
       longest = argv[i];
  }
  printf("le mot le plus court est: '%s'\n", shortest);
  printf("le mot le plus long est: '%s'\n", longest);
}
