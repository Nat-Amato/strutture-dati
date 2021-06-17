#ifndef _ORDERED_LIST_H
#define _ORDERED_LIST_H

#include "linked_list.h"
#include <string>

template <class T>
class Ordered_list{
public:
	typedef typename Linked_list<T>::position position;

	Ordered_list();
	Ordered_list(Linked_list<T> &);
	void insert(T); // inserisce un elemento
	void remove(T); // rimuove un elemento
	bool search(T); // cerca un elemento
	void merge(Ordered_list<T> &);  // fonde con una lista ordinata
	Linked_list<T>& getList();

private:
	Linked_list<T> L;
};

template<class T>
Ordered_list<T>::Ordered_list() {

}

template< class T >
Ordered_list<T>::Ordered_list(Linked_list<T>& l) {
	position i;
	for (i = l.begin(); !l.end(i); i = l.next(i)) {
		insert(l.read(i));
	}
}

template< class T >
void Ordered_list<T>::insert(T t) {
	position i;
	bool verifica = false;
	if (L.empty())
		L.insert(t, L.begin());
	else {
		for (i = L.begin(); verifica == false; i = L.next(i)) {
			if (L.end(i)) {
				L.insert(t, i);
				verifica = true;
			}
			if (verifica == false && t <= L.read(i)) {
				L.insert(t, i);
				verifica = true;
			}
		}
	}
}

template< class T >
void Ordered_list<T>::remove(T t) {
	position i;
	bool verifica = false;
	if (L.empty()) {

	}
	else {
		for (i = L.begin(); !L.end(i) && verifica == false; i = L.next(i)) {
			if (t == L.read(i)) {
				L.erase(i);
				verifica = true;
			}
		}
	}
}


template< class T >
bool Ordered_list<T>::search(T t) {
	position i;
	bool verifica = false;
	if (L.empty()) {

	}
	else {
		for (i = L.begin(); !L.end(i) && verifica == false; i = L.next(i)) {
			if (t == L.read(i))
				verifica = true;
		}
	}
	return verifica;
}


template< class T >
void Ordered_list<T>::merge(Ordered_list<T>& l) {
	position i;
	for (i = l.getList().begin(); !l.getList().end(i); i = l.getList().next(i)) {
		insert(l.getList().read(i));
	}
}

template< class T >
Linked_list<T>& Ordered_list<T>::getList() {
	return L;
}

#endif // _ORDERED_LIST_H
