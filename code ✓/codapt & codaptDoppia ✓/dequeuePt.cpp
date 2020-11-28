#include <iostream>

using namespace std;

template <class T>
class nodo {
public:
	nodo<T> *next;
	nodo<T> *prec;
	T value;
};

template <class T>
class dequeue {
public:
	dequeue();
	dequeue(dequeue<T>&);
	~dequeue();

	bool empty();
	int size();
	void insertH(T);
	void insertT(T);
	T readH();
	T readT();
	void removeH();
	void removeT();

private:
	nodo<T>* head;
	nodo<T>* tail;
	nodo<T>* first;
	int s;
	bool creatoH;
	bool creatoT;
};

template <class T>
dequeue<T>::dequeue() {
	head = tail = nullptr;
	s = 0;
	creatoT = false;
	creatoH = false;
}

template <class T>
dequeue<T>::dequeue(dequeue<T>& q) {
	head = tail = nullptr;
	s = 0;
	creatoT = false;
	creatoH = false;
	T appoggio;
	for (int i = 0; i < q.size(); i++) {
		appoggio = q.readH();
		q.removeH();
		q.insertT(appoggio);
		insertT(appoggio);
	}
}

template <class T>
dequeue<T>::~dequeue() {
	while (!empty()) {
		removeH();
	}
		
}

template <class T>
bool dequeue<T>::empty() {
	return (s == 0);
}

template <class T>
int dequeue<T>::size() {
	return s;
}

template <class T>
void dequeue<T>::insertT(T v) {
	nodo<T> *tmp = new nodo<T>();
	if (empty())
		head = tail = tmp;
	else
		tail->next = tmp;
	tmp->next = nullptr;
	tmp->prec = tail;
	tmp->value = v;
	tail = tmp;
	s++;
} 

template <class T>
void dequeue<T>::insertH(T v) {
	nodo<T> *tmp = new nodo<T>();
	if (empty())
		head = tail = tmp;
	else
		head->prec = tmp;
	tmp->next = head;
	tmp->prec = nullptr;
	tmp->value = v;
	head = tmp;
	s++;
}

template <class T>
T dequeue<T>::readH() {
	return head->value;
}

template <class T>
T dequeue<T>::readT() {
	return tail->value;
}

template <class T>
void dequeue<T>::removeH() {
	nodo<T> *tmp = head;
	head = head->next;
	delete tmp;
	s--;
}

template <class T>
void dequeue<T>::removeT() {
	nodo<T> *tmp = tail;
	tail = tail->prec;
	delete tmp;
	s--;
}