/*
  Dans l’exemple maxf.c:

  * Rajouter une fonction minTableau() qui retourne la valeur minimale
  * du tableau

  * Rajouter une fonction secondTableau() qui retourne la 2nde valeur
  * la plus grande du tableau (différente de la valeur maximale)

 */

#include <stdio.h>
int max(int a, int b) {
  if (a > b) // Parenthèses OBLIGATOIRES
    return a;
  else
    return b;
}

int min(int a, int b) {
  if (a < b) // Parenthèses OBLIGATOIRES
    return a;
  else
    return b;
}

int maxTableau(int tableau[],
	       int nbElements) {
  int resultat = tableau[0];
  int i = 1;
  while (i < nbElements) { // celles-ci aussi
    resultat = max(resultat, tableau[i]);
    i = i + 1;
  }
  return resultat;
}

int secondTableau(int tableau[],
	       int nbElements) {
  int premier;
  int second;
  if (tableau[0] < tableau[1]) {
      premier = tableau[1];
      second = tableau[0];
  } else {
      premier = tableau[1];
      second = tableau[0];
  }
  for (int i = 2; i < nbElements; i = i + 1) {
      if (tableau[i] >= premier) {
          second = premier;
          premier = tableau[i];
      } else if (tableau[i] >= second) {
          second = tableau[i];
      }
  }
  return second;
}

int minTableau(int tableau[],
	       int nbElements) {
  int resultat = tableau[0];
  int i = 1;
  while (i < nbElements) { // celles-ci aussi
    resultat = min(resultat, tableau[i]);
    i = i + 1;
  }
  return resultat;
}

#define N 6

int main(int argc, char **argv) {
  int tab[N] = {10, 20, 42, 40, 40, 42};
  int res = maxTableau(tab, N);
  printf("Max du tableau: %i\n", res);
  res = minTableau(tab, N);
  printf("Min du tableau: %i\n", res);
  res = secondTableau(tab, N);
  printf("2nd du tableau: %i\n", res);
  return 0;
}
