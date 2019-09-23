#include <stdio.h>
#define N 5

int main(int argc, char **argv) {
    int tab[N] = {12, 14, 10, 20, 50};

    for (int i=0; i < N  - 1; i = i + 1) {
        if (tab[i+1] < tab[i])
            printf("%i\n", tab[i]);
        else printf("%i ", tab[i]);        
    }
    printf("%i\n", tab[N -1]);

}
