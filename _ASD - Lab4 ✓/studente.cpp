#include "studente.h"

studente::studente() {
	esami.resize(numEsami);
	esami[0].setEsame("ASD");
	esami[1].setEsame("Analisi");
	esami[2].setEsame("Linguaggi");
	esami[3].setEsame("Base di dati");
	esami[4].setEsame("MAP");
}

studente::studente(string nome1, string nome2, string nome3, string nome4, string nome5) {
	esami.resize(numEsami);
	esami[0].setEsame(nome1);
	esami[1].setEsame(nome2);
	esami[2].setEsame(nome3);
	esami[3].setEsame(nome4);
	esami[4].setEsame(nome5);
}

void studente::setMatricola(string m) {
	matricola = m;
}

void studente::setNome(string n) {
	nome = n;
}

string studente::getMatricola() {
	return matricola;
}

string studente::getNome() {
	return nome;
}

int studente::getNumEsami() {
	return numEsami;
}

void studente::setEsame(int v, int i) {
	esami[i].setVoto(v);
}

int studente::getVotoEsame(int i) {
	return esami[i].getVoto();
}

string studente::getNomeEsame(int i) {
	return esami[i].getEsame();
}

bool studente::getSostenuto(int i) {
	return esami[i].isSostenuto();
}

double studente::getMedia() {
	double media = 0;
	int molt = 0;
	for (int i = 0; i < numEsami; i++) {
		if (esami[i].isSostenuto()) {
			media += esami[i].getVoto();
			molt++;
		}
	}
	return (media / molt);
}

void studente::printStudente() {
	cout << nome << " Mat: " << matricola << endl;
	for (int i = 0; i < numEsami; i++) {
		if (esami[i].isSostenuto())
			cout << esami[i].getEsame() << ": " << esami[i].getVoto() << endl;
	}
	cout << "Media: " << getMedia() << endl;
}
