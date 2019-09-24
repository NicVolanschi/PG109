#include <stdio.h>
#include <stdlib.h>

int bi(int n) {
    return n % 400 == 0 ||
        (n % 4 == 0 && n % 100 != 0);
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    if (n % 400 == 0)
        printf("bi");
    else if (n % 100 == 0)
        printf("pas bi");
    else if (n % 4 == 0)
        printf("bi");
    else
        printf("pas bi");
    printf("\n");

    printf("bi(%i)=%i\n", n, bi(n));
}
