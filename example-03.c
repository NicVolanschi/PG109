//example-03.c
#include <stdio.h>

int main(int argc, char* argv[]) {
  int a = 5;
  int b = 3;
  int b0 = b;
  int res = 0;
  while (b > 0) {
    res = res + a;
    b = b - 1;
  }
  printf("Le produit est: %i\n", res);
  if (res == a * b0) {
    printf("resultat correct!\n");
  } else {
    printf("bug!\n");
  }
  return 0;
}
