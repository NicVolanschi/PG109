#include <stdio.h>

void mystrcpy(char dest[], char source[]){
  int i = 0;
  while(source[i] != '\0') {
    dest[i] = source[i];
    i = i + 1;
  }
  dest[i] = source[i];
}

int mystrlen(char s[]) {
  int len = 0;
  while(s[len] != '\0') {
    len = len + 1;
  }
  return len;
}

void mystrcat(char s1[], char s2[]) {
  int i = mystrlen(s1); // position on end(s1)
  int j = 0;
  while(s2[j] != '\0') {
    s1[i] = s2[j];
    i = i + 1;
    j = j + 1;
  }
  s1[i] = s2[j]; // add trailing 0
}

int mystrcmp(char *s1, char *s2) {
  int i = 0;
  while (s1[i] == s2[i] && s1[i] != 0)
    i = i + 1;
  return s1[i] - s2[i];
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("usage: %s str1 str2\n", argv[0]);
    return 1;
  }
  char s1[20];
  mystrcpy(s1, argv[1]);
  printf("s1='%s'\n", s1);
  printf("len(s1)=%d\n", mystrlen(s1));
  mystrcat(s1, argv[2]);
  printf("s1='%s'\n", s1);
  printf("cmp('%s','%s')=%d\n", argv[1], argv[2], mystrcmp(argv[1], argv[2]));
}
