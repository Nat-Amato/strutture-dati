#include "matrice.h"
#include<iostream>

using namespace std;

int main() {

	int righe1, colonne1, righe2, colonne2;
	righe1 = 2;
	colonne1 = 3;
	matrice m(colonne1, righe1);

	m.scrivimatrice(0, 0, 2.0);
	m.scrivimatrice(0, 1, 4.0);
	m.scrivimatrice(0, 2, 1.0);

	m.scrivimatrice(1, 0, 2.0);
	m.scrivimatrice(1, 1, 3.0);
	m.scrivimatrice(1, 2, 9.0);

	righe2 = 3;
	colonne2 = 3;
	matrice m2(colonne2, righe2);

	m2.scrivimatrice(0, 0, 1.0);
	m2.scrivimatrice(0, 1, 2.0);
	m2.scrivimatrice(0, 2, 3.0);

	m2.scrivimatrice(1, 0, 3.0);
	m2.scrivimatrice(1, 1, 6.0);
	m2.scrivimatrice(1, 2, 1.0);

	m2.scrivimatrice(2, 0, 2.0);
	m2.scrivimatrice(2, 1, 9.0);
	m2.scrivimatrice(2, 2, 7.0);
	

	m.prodotto(m2);
	
	for (int i = 0; i < righe1; i++) {
		for (int j = 0; j < colonne2; j++) {
			cout << m.leggimatrice(i, j) << " ";
		}
		cout << endl;
	}

	return 0;
}


