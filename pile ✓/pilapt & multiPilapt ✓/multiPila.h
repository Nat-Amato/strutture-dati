
#ifndef _MULTIPILA_H
#define _MULTIPILA_H

#include "pilapt.h"

template<class T>
class MultiPila {
public:
	MultiPila(int);
	~MultiPila();
	void push(T, int);
	T pop(int);

private:
	Pila<T> *multiPile;
	int grandezza;
};

template<class T>
MultiPila<T>::MultiPila(int n) {
	grandezza = n;
	multiPile = new Pila<T>[grandezza];
}

template<class T>
MultiPila<T>::~MultiPila() {
}

template<class T>
void MultiPila<T>::push(T elemento, int i) {
	multiPile[i].inPila(elemento);
}

template<class T>
T MultiPila<T>::pop(int i) {
	T appoggio;
	appoggio = multiPile[i].leggiPila();
	multiPile[i].fuoriPila();
	return appoggio;
}






























#endif // _MULTIPILA_H
