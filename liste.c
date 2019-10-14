#include <stdio.h>
#include <stdlib.h>

typedef struct ent *pt ;  // pt = pointeur vers struct ent

struct ent {
  int valeur;
  pt suiv;
};

// doit être appelée avec le pointeur de début de la liste  ex : ajout(&deb,56)
void ajoutdeb (pt * d, int data) {
  pt paux = (pt) malloc(sizeof(struct ent));
  paux->valeur = data;
  paux->suiv = *d;
  *d = paux;
}

// doit être appelée avec le pointeur de début de la liste ex: detruit (&L,42)
void supprime (pt * d, int data) {
  pt p = *d;
  pt prec = NULL;
  while (p != NULL) {
    if (p->valeur == data) { // on a trouvé l'élément à supprimer
      if(prec != NULL) prec->suiv = p->suiv;
      else *d = (*d)->suiv;
      free(p);
      return;
    }
    // on avance dans la liste
    prec = p;
    p = p->suiv;
  }
}

void suppr (pt * d, int data) {
  while (*d != NULL) {
    if ((*d)->valeur == data) { // on a trouvé l'élément à supprimer
      pt p = *d;
      *d = (*d)->suiv;
      free(p);
      return;
    }
    d = &(*d)->suiv; // on avance dans la liste
  }
}

void affiche(pt deb) {
  pt paux = deb;
  // on prend un pointeur auxiliaire pour ne pas perdre l'adresse de début de la liste
  while(paux != NULL) {
    printf("%d ", paux->valeur);
    paux = paux->suiv;
  }
  printf("\n");
}

pt adresse(pt deb, int data) {
  pt paux = deb;
  // on prend un pointeur auxiliaire pour ne pas perdre l'adresse de début de la liste
  while(paux != NULL) {
     if ( paux->valeur == data) {
         return paux;
     }
     paux = paux->suiv;
  }
  return NULL;
}

void detruit_liste(pt *deb) {
  pt paux = *deb;
  // on prend un pointeur auxiliaire pour ne pas perdre l'adresse de début de la liste
  while(paux != NULL) {
      pt tmp = paux;
      free(paux);
     paux = tmp->suiv;
  }
  *deb = NULL;
}

int main(int argc, char *argv[]) {
  // Créer une liste contenant les arguments de la commande
  pt deb = NULL;
  for (int i = argc - 1; i > 0; i--) {
    ajoutdeb(&deb, atoi(argv[i]));
  }

  // Afficher la liste
  affiche(deb);

  // Ajouter l'élèment 99 à la fin

  // Si l'élément 55 existe signaler un succès & supprimer;
  // sinon signaler un échec
  if (adresse(deb, 55) != NULL)
    printf("succes\n");
    else  printf("echec\n");


  // Destruction de toute la liste
  detruit_liste(&deb);
  affiche(deb);
}
