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

  for (i = 0; i < righe; i++) {
	  for (int j = 0; j < colonne; j++) {
		  elementi[i][j] = 0.0;
	  }
  }
     
}
/*
matrice::matrice(const matrice& M) {
	matrice(M.colonne, M.righe);
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			elementi[i][j] = M.elementi[i][j];
		}
	}
}
*/

matrice::matrice(const matrice& M) {
	colonne = M.colonne;
	righe = M.righe;

	int i;
	elementi = new tipoelem*[righe];
	for (i = 0; i < righe; i++)
		elementi[i] = new tipoelem[colonne];

	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			elementi[i][j] = M.elementi[i][j];
		}
	}
}

matrice& matrice::operator=(const matrice& M) {
	colonne = M.colonne;
	righe = M.righe;

	int i;
	elementi = new tipoelem*[righe];
	for (i = 0; i < righe; i++)
		elementi[i] = new tipoelem[colonne];

	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			elementi[i][j] = M.elementi[i][j];
		}
	}
	return *this;
}

matrice::~matrice() {
	for (int i = 0; i < righe; i++) {
		delete[] elementi[i];
	}
	delete[] elementi;
}

tipoelem matrice::leggimatrice(int i, int j) {
	return elementi[i][j];
}

void matrice::scrivimatrice(int i, int j, tipoelem e) {
	elementi[i][j] = e;
}

void matrice::prodottoScalare(double s) {
	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			elementi[i][j] *= s;
		}
	}
}

matrice& matrice::trasposta(const matrice& M) {
	colonne = M.righe;
	righe = M.colonne;

	int i;
	elementi = new tipoelem*[righe];
	for (i = 0; i < righe; i++)
		elementi[i] = new tipoelem[colonne];

	for (int i = 0; i < righe; i++) {
		for (int j = 0; j < colonne; j++) {
			elementi[i][j] = M.elementi[j][i];
		}
	}
	return *this;
}

matrice& matrice::prodotto(matrice& M) {
	
	if (righe == M.righe && colonne == M.colonne && righe == colonne) {
		for (int i = 0; i < righe; i++) {
			for (int j = 0; j < colonne; j++) {
				elementi[i][j] *= M.elementi[i][j];
			}
		}
	}
	if (colonne == M.righe) {
		matrice m(*this);
		colonne = M.colonne;

		int i;
		elementi = new tipoelem*[righe];
		for (i = 0; i < righe; i++)
			elementi[i] = new tipoelem[colonne];


		for (int i = 0; i < righe; i++) {
			for (int j = 0; j < colonne; j++) {
				elementi[i][j] = opInterne(m, M, i, j);
			}
		}

	}

	return *this;
}

tipoelem matrice::opInterne(matrice& m1, matrice& m2, int colonna1, int riga2) {

	tipoelem somma = 0;
	for (int j = 0; j < m1.colonne; j++) {
		somma += m1.leggimatrice(colonna1, j) * m2.leggimatrice(j, riga2);
	}
	return somma;

}
