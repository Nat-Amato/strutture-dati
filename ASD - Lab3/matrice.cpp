#include "matrice.h"

// costruttore
matrice::matrice(int c, int r){
  colonne = c;
  righe = r;
  // allocazione dinamica della matrice
  int i;
  elementi = new tipoelem* [righe];
  for (i=0; i < righe; i++)
    elementi[i] = new tipoelem[colonne];
  // inizializzazione degli elementi
     ...
}
