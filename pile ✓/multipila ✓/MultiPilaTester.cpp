#include <iostream>
#include "multiPila.h"

using namespace std;

int main()
{
	
	MultiPila<int> p(2);
	p.push(1, 1);
	p.push(2, 1);
	p.push(3, 1);
	p.push(4, 0);
	p.push(5, 0);

	MultiPila<int> p2(1);

	p2 = p;

	cout << p2.pop(0);
	cout << p2.pop(0);
	cout << p2.pop(1);
	cout << p2.pop(1);
	cout << p2.pop(1);

	/*
	Pila<int> p;

	p.inPila(1);
	p.inPila(2);
	p.inPila(3);
	p.inPila(1);
	p.inPila(2);
	p.inPila(3);
	p.inPila(4);
	p.inPila(4);
	p.inPila(1);

	Pila<int> p2;

	p2 = p;

	for (; !p2.pilaVuota(); p2.fuoriPila()) {
		cout << p2.leggiPila();
	}
	*/
}
