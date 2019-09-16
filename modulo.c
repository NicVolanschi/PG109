#include <stdio.h>

int main(int argc, char **argv) {
  int a = -13;
  int a0 = a;
  int b = 3;
  //int res;
  if (b == 0) {
    printf("erreur: division par 0\n");
    return 1;
  }
  if (b < 0) {
    printf("erreur: b négatif\n");
    return 2;
  }
  if (a < 0) {
    while (a <= -b) {
      a = a + b;
    }
  } else {
    while (a >= b) {
      a = a - b;
    }
  }
  printf("%i modulo %i = %i\n", a0, b, a);
  if (a0 % b == a) {
    printf("bon résultat\n");
  } else {
    printf("bug, le résultat correct est %i!\n", a0 % b);
  }
}
