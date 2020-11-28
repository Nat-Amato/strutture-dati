#ifndef _STUDENTE
#define _STUDENTE
#include <string>

using namespace std;

class studente{
private:
	int matricola;
	string nome;
	string cognome;
	int eta;
public:
	void setMatricola(int);
	void setNome(string);
	void setCognome(string);
	void setEta(int);

	int getMatricola();
	string getNome();
	string getCognome();
	int getEta();
};

#endif /* _STUDENTE */
