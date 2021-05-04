#include "hash_table.h"
#include <iostream>

using namespace std;

int main() {

	hash_table<string, int> t(8);
	mypair<string, int> p;
	p.chiave = "prima";
	p.valore = 1;
	t.insert(p);

	p.chiave = "seconda";
	p.valore = 21;
	t.insert(p);

	p.chiave = "terza";
	p.valore = 3;
	t.insert(p);

	p.chiave = "sesta";
	p.valore = 21;
	t.insert(p);

	p.chiave = "ultima";
	p.valore = 41;
	t.insert(p);

	p.chiave = "prova";
	p.valore = 666;
	t.insert(p);

	p.chiave = "prova2";
	p.valore = 777;
	t.insert(p);

	p.chiave = "prova3";
	p.valore = 888;
	t.insert(p);

	int valori[t.size()];
	t.values(valori);

	string chiavi[t.size()];
	t.keys(chiavi);

	for (int i = 0; i < t.size(); i++) {
		cout << valori[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < t.size(); i++) {
		cout << chiavi[i] << endl;
	}

	hash_table<string, int> t2(t);

	p.chiave = "prova4";
	p.valore = 777;
	t2.insert(p);

	p.chiave = "prova5";
	p.valore = 888;
	t2.insert(p);

	cout << endl;

	int valori2[t2.size()];
	t2.values(valori2);

	string chiavi2[t2.size()];
	t2.keys(chiavi2);

	for (int i = 0; i < t2.size(); i++) {
		cout << valori2[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < t2.size(); i++) {
		cout << chiavi2[i] << endl;
	}





	hash_table<string, int> d1(4);
	p.chiave = "prima";
	p.valore = 1;
	d1.insert(p);

	p.chiave = "seconda";
	p.valore = 21;
	d1.insert(p);

	p.chiave = "terza";
	p.valore = 3;
	d1.insert(p);

	p.chiave = "sesta";
	p.valore = 21;
	d1.insert(p);


	hash_table<string, int> d2(4);
	p.chiave = "prima";
	p.valore = 1;
	d2.insert(p);

	p.chiave = "seconda";
	p.valore = 21;
	d2.insert(p);

	p.chiave = "terza";
	p.valore = 3;
	d2.insert(p);

	p.chiave = "sesta";
	p.valore = 21;
	d2.insert(p);


	cout << endl;
	cout << endl;
	cout << endl;

	if(d1<d2)
		cout << "vero 1";

	cout << endl;
	cout << endl;
	cout << endl;

	if(d1==d2)
		cout << "vero 2";









	//cout << t.find("terza")->valore;

	//cout<< t.containsValue(3);

}

