#include <stdio.h>
#include <string.h>

#define N 20 // nbre max d’ingrédients différents
#define SIZE 32 // taille max d’un nom d’ingrédient
struct ingredient {
  char name[SIZE];
  int quant;
};
struct ingredient tab[N]; // liste d’ingrédients totalisés
int n = 0; // nbre d’ingrédients dans tab[]

int read_ingredient(struct ingredient *s) {
    return scanf("%i", &(s->quant)) == 1 &&
            scanf("%s", s->name) == 1;
}

void print_ingredient(struct ingredient *s) {
    printf("%i %s\n", (*s).quant, s->name);
}

void add_ingredient(struct ingredient *s) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(s->name,  tab[i].name)) {
            tab[i].quant += s->quant;
            return;
        }
    }
    tab[n] = *s;
    n++;
}

int main(int argc, char *argv[]) {
  struct ingredient ingredient1;
  while (read_ingredient(&ingredient1)) {
    add_ingredient(&ingredient1);
  }
  for (int i = 0; i < n; i++) {
    print_ingredient(&tab[i]);
  }
}
