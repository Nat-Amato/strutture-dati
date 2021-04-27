
#ifndef _MULTIPILA_H
#define _MULTIPILA_H

#include "pilapt.h"

template<class T>
class MultiPila {
public:
	MultiPila();
	MultiPila(int);
	~MultiPila();
	void push(T, int);
	T pop(int);
	int getGrandezza();
	bool pilaVuota(int);

	MultiPila<T>& operator=(MultiPila<T>&);
private:
	Pila<T> *multiPile;
	int grandezza;
};

template<class T>
MultiPila<T>::MultiPila() {
	grandezza = 1;
	multiPile = new Pila<T>[grandezza];
}

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

template <class T>
int MultiPila<T>::getGrandezza() {
	return grandezza;
}

template <class T>
bool MultiPila<T>::pilaVuota(int n) {
	return multiPile[n].pilaVuota();
}

template <class T>
MultiPila<T>& MultiPila<T>::operator=(MultiPila<T>& m) {
	Pila<T> appoggio;
	grandezza = m.getGrandezza();
	multiPile = new Pila<T>[grandezza];
	for (int i = 0; i < grandezza; i++) {
		while (!m.pilaVuota(i)) {
			appoggio.inPila(m.pop(i));
		}
		for (; !appoggio.pilaVuota(); appoggio.fuoriPila()) {
			m.push(appoggio.leggiPila(), i);
			push(appoggio.leggiPila(), i);
		}
	}
	return *this;
}

#endif // _MULTIPILA_H
