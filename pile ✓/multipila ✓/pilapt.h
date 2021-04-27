#ifndef _PILAPT_H
#define _PILAPT_H

/*
quicksort(int *a, int lower, int upper){
  int pivot = a[(upper-lower)/2];
  int l=lower, r=upper;

  inpila([lower,upper])
    while(!empty)
  
  while(r!=l){
    while (l<r && a[l]<=pivot)
      l++;
    while (r>l && a[r]>pivot)
      r--;
    if (r!=l)
      swap(a,l,r);
  }
  quicksort(a, lower, l);
  quicksort(a, l+1, upper);
}
*/



template <class T>
class cella{
public:
  T e;
  cella<T> *prev;
};

template <class Elemento>
class Pila
  {
  public:
    typedef Elemento tipoelem;
    Pila();
    ~Pila();
    void creaPila();
    bool pilaVuota() const;
    tipoelem leggiPila() const;
    void fuoriPila();
    void inPila(tipoelem);

	Pila<Elemento>& operator=(Pila<Elemento>&);
  private:
    cella<tipoelem>* testa;
  };

template <class Elemento>
Pila<Elemento>::Pila()
{
  testa = nullptr;
}


template <class Elemento>
Pila<Elemento>::~Pila()
{
  while (!pilaVuota())
    fuoriPila();
};

template <class Elemento>
void Pila<Elemento>::creaPila()
{
  testa=nullptr;
}

template <class Elemento>
bool Pila<Elemento>::pilaVuota() const
  {
    return testa==nullptr;
  }

template <class Elemento>
Elemento Pila<Elemento>::leggiPila() const
  {
    return testa->e;
  }

template <class Elemento>
void Pila<Elemento>::fuoriPila()
{
  if (!pilaVuota())
    {
      cella<Elemento> *tmp = testa;
      testa = testa->prev;
      delete tmp;
    }
}


/* inPila con duplicati
template <class Elemento>
void Pila<Elemento>::inPila(tipoelem el)
{
  cella<Elemento> *tmp = new cella<Elemento>();
  tmp->e = el;
  tmp->prev = testa;
  testa = tmp;
}
*/

// inPila senza duplicati
template <class Elemento>
void Pila<Elemento>::inPila(tipoelem el)
{
	bool verifica = false;
	Pila<Elemento> appoggio;

	for (; !pilaVuota() && !verifica; fuoriPila()) {
		if (el == leggiPila())
			verifica = true;
		appoggio.inPila(leggiPila());
	}
	if (!appoggio.pilaVuota()) {
		for (; !appoggio.pilaVuota(); appoggio.fuoriPila()) {
			inPila(appoggio.leggiPila());
		}
	}
	if (!verifica) {
		cella<Elemento> *tmp = new cella<Elemento>();
		tmp->e = el;
		tmp->prev = testa;
		testa = tmp;
	}
}

template <class Elemento>
Pila<Elemento>& Pila<Elemento>::operator=(Pila<Elemento>& p) {
	Pila<Elemento> appoggio;
	for (; !pilaVuota(); fuoriPila()) {}
	for (; !p.pilaVuota(); p.fuoriPila()) {
		appoggio.inPila(p.leggiPila());
	}
	for (; !appoggio.pilaVuota(); appoggio.fuoriPila()) {
		p.inPila(appoggio.leggiPila());
		inPila(appoggio.leggiPila());
	}
	return *this;
}

#endif // _PILAVT_H