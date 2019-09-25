#include <stdio.h>
#include <string.h>

int mask(char c) {
    return (1U << 31) >> (c - 'a');
}

int setof(char *s) {
    int set = 0; // 000000000
    for (int i = 0; s[i] != 0; i++) {
        set = set | mask(s[i]);
    }
    return set;
}

void print_set(int set) {
    for (char c = 'a'; c <= 'z'; c++) {
        if (mask(c) & set) {
            printf("%c", c);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    printf("le set de %s est %u\n", argv[1], setof(argv[1]));
    print_set(setof(argv[1]));
}
