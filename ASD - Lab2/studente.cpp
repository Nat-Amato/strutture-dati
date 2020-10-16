#include "studente.h"
#include <iostream>

void studente::setMatricola(int a){
	if(a>255312 && a< 499999)
		matricola = a;
	else
		cout << "La matricola non è compresa tra 255312 e 499999" << endl;
}

void studente::setNome(string n){
	if(n.length()<31)
		nome = n;
	else
		cout << "Il nome è più lungo di 30 caratteri" << endl;
}

void studente::setCognome(string c){
	if(c.length()<31)
		cognome = c;
	else
		cout << "Il cognome è più lungo di 30 caratteri" << endl;
}

void studente::setEta(int a){
	if(a>12 && a<105)
		eta = a;
	else
		cout << "L'età non è compresa tra 12 e 105" << endl;
}

int studente::getMatricola(){
	return matricola;
}

string studente::getNome(){
	return nome;
}

string studente::getCognome(){
	return cognome;
}
int studente::getEta(){
	return eta;
}
