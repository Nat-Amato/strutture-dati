/** BOZZA **/

template <class T>
class nodo{
public:
  nodo<T> *next;
  T value;
};

template <class T>
class queue{
public:
	queue();
	queue(queue<T>&);
	~queue();
  
	bool empty();
	int size();
	void insert(T);
	T read();
	void remove();

	void positive(queue<int>&);
  
private:
  nodo<T>* head;
  nodo<T>* tail;
  int s;
};

template <class T>
queue<T>::queue() {
	head = tail = nullptr;
	s = 0;
}

template <class T>
queue<T>::queue(queue<T>& q) {
	head = tail = nullptr;
	s = 0;
	T appoggio;
	for (int i = 0; i < q.size(); i++) {
		appoggio=q.read();
		q.remove();
		q.insert(appoggio);
		insert(appoggio);
	}
}


template <class T>
queue<T>::~queue() {
	while (!empty())
		remove();
}

template <class T>
bool queue<T>::empty() {
	return (head == nullptr);
}

template <class T>
int queue<T>::size() { 
	return s; 
}

template <class T>
void queue<T>::insert(T v) {
	nodo<T> *tmp = new nodo<T>();
	if (empty())
		head = tail = tmp;
	else
		tail->next = tmp;
	tmp->next = nullptr;
	tmp->value = v;
	tail = tmp;
	s++;
}

template <class T>
T queue<T>::read() {
	return head->value;
}

template <class T>
void queue<T>::remove() {
	nodo<T> *tmp = head;
	head = head->next;
	delete tmp;
	s--;
}

template <class T>
void queue<T>::positive(queue<int>& c) {
	int appoggio;
	for (int i = 0; i < c.size(); i++) {
		appoggio = c.read();
		c.remove();
		if (appoggio >= 0)
			insert(appoggio);
		c.insert(appoggio);
	}
}

