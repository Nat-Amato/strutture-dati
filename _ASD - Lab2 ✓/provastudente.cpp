#include "studente.h"
#include <iostream>

int main() {

	int m;
	string n;
	string c;
	int e;
	studente studente;


	do{
		cout << "Inserire matricola: ";
		cin >> m;
		studente.setMatricola(m);
	}while(m<255312 || m>499999);

	do{
		cout << "Inserire Nome: ";
		cin >> n;
		studente.setNome(n);
	}while(n.length()>30);

	do{
		cout << "Inserire Cognome: ";
		cin >> c;
		studente.setCognome(c);
	}while(c.length()>30);

	do{
		cout << "Inserire età: ";
		cin >> e;
		studente.setEta(e);
	}while(e<12 || e>105);

	cout << studente.getMatricola() << endl;
	cout << studente.getNome() << endl;
	cout << studente.getCognome() << endl;
	cout << studente.getEta() << endl;
	return 0;
}
