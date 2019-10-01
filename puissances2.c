#include <stdio.h>
#include <stdlib.h>

void fois2(int *x) {
    (*x) = (*x) * 2;
}

int main(int argc, char * *argv) {
    int n = atoi(argv[1]);
    int p = 1;
    for (int i = 1; i <= n; i++) {
        fois2(&p);
        printf("2^%i=%i\n", i, p);
    }
}
