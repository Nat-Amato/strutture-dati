#include <string>
#include <vector>
#include <iostream>
#include "esame.h"

using namespace std;

class studente{
 public:
	studente();
	studente(string, string, string, string, string);
	void setMatricola(string);
	void setNome(string);
	string getMatricola();
	string getNome();
	int getNumEsami();
	void setEsame(int, int);
	int getVotoEsame(int);
	string getNomeEsame(int);
	bool getSostenuto(int);
	double getMedia();
	void printStudente();

 private:
	const int numEsami = 5;
	vector<esame> esami;
	string matricola;
	string nome;
};
