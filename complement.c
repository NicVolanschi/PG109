#include <stdio.h>

int nbits(unsigned int n) {
    int count = 0;
    while (n != 0) {
        n = n / 2;
        count = count + 1;
    }
    return count;
}

int invbin(unsigned int n, char tab[]) {
    int count = 0;
    while (n != 0) {
        tab[count] = '0' + (n % 2);
        n = n / 2;
        count = count + 1;
    }
    tab[count + 1] = 0;
    return count;
}

void reverse(char tab[]) {
    // ...
}

int main(int argc, char **argv) {
    int i = 23;
    printf("nombre de bits de %i est %i\n", i, nbits(i));
    char inv[nbits(i) + 1];
    invbin(i, inv);
    printf("la representation binaire a l'envers de %i est %s\n",
        i, inv);
}
