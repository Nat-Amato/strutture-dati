#ifndef _Bin_treecC_H_
#define _Bin_treecC_H_

#include "Bin_tree.h"
#include "exceptions.h"
#include <string>

using namespace std;

template <class T>
class Bin_treec : public Bin_tree<T, int>{
    static const int NIL = -1;

  public:

	typedef typename Bin_tree<T, int>::value_type value_type;
	typedef typename Bin_tree<T, int>::Nodo Nodo;

    struct _cella{
        Nodo genitore;
        Nodo sinistro;
        Nodo destro;
        value_type valore;
        int nodiSucc;
      };

    typedef struct _cella Cella;

    // costruttori e distruttori
    Bin_treec();
    Bin_treec(int);
    Bin_treec(string);
    ~Bin_treec();

    // operatori
    void create();
    bool empty() const;

    Nodo root() const;
    Nodo parent(Nodo) const;
    Nodo sx(Nodo) const;
    Nodo dx(Nodo) const;
    bool sx_empty(Nodo) const;
    bool dx_empty(Nodo) const;

    //void costr(Bin_treec<T>);
    void erase(Nodo);

    T read(Nodo) const;
    int nNodiSucc(Nodo) const;

    void write(Nodo , value_type );

    void ins_root(Nodo);
    void ins_sx(Nodo);
    void ins_dx(Nodo);

    void eliminaPari(Nodo);


    void mutation(Bin_treec<T> &, Nodo, Bin_treec<T> &, Nodo); //nel primo albero viene aggiunto il secondo. Il primo nodo appartiene al primo albero, il secondo nodo al secondo

  protected:
    int MAXLUNG;
    Cella *spazio;
    int nNodi;
    Nodo inizio;
    Nodo libera;
    void modificaNodiSucc(Nodo, char);
    void copia(Bin_treec<T> &, Nodo, Bin_treec<T> &, Nodo);
    void arithmeticParseTree(string);
};

template <class T>
Bin_treec<T>::Bin_treec()
{
  MAXLUNG = 100;
  spazio = new Cella[MAXLUNG];
  create();
}

template <class T>
Bin_treec<T>::Bin_treec(int nNodi): MAXLUNG(nNodi)
{
  spazio = new Cella[nNodi];
  create();
}

template <class T>
Bin_treec<T>::Bin_treec(string s): MAXLUNG(s.size()){
	spazio = new Cella[s.size()];
	create();
	this->arithmeticParseTree(s);
}


template <class T>
Bin_treec<T>::~Bin_treec()
{
  erase(inizio);
  delete[] spazio;
}

template <class T>
void Bin_treec<T>::create()
{
  inizio = NIL;
  for (int i = 0; i < MAXLUNG; i++)
    {
      spazio[i].sinistro = (i+1) % MAXLUNG;
    }

  libera = 0;
  nNodi = 0;
}

template <class T>
bool Bin_treec<T>::empty() const
{
  return(nNodi == 0);
}

template <class T>
typename Bin_treec<T>::Nodo Bin_treec<T>::root() const
{
  return(inizio);
}

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::parent(Nodo n) const
{
  if (n != inizio)
    return (spazio[n].genitore);
  else
    return(n);
}

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::sx(Nodo n) const
{
  if (!sx_empty(n))
    return (spazio[n].sinistro);
  else
    return(n);
};

template <class T>
typename     Bin_treec<T>::Nodo Bin_treec<T>::dx(Nodo n) const
{
  if (!dx_empty(n))
    return (spazio[n].destro);
  else
    return(n);
}

template <class T>
bool Bin_treec<T>::sx_empty(Bin_treec<T>::Nodo n) const
{
  return (spazio[n].sinistro == NIL);
}

template <class T>
bool Bin_treec<T>::dx_empty(Bin_treec<T>::Nodo n) const
{
  return (spazio[n].destro == NIL);
}

template <class T>
void Bin_treec<T>::ins_root(Bin_treec<T>::Nodo n)
{
  if (inizio == NIL)
    {
      inizio = libera;
      libera = spazio[libera].sinistro;
      spazio[inizio].genitore = NIL;
      spazio[inizio].sinistro = NIL;
      spazio[inizio].destro = NIL;
      spazio[inizio].nodiSucc = 1;
      nNodi++;
    }
	else
		throw RootExists();
}


template <class T>
void Bin_treec<T>::ins_sx(Nodo n)
{
	if (inizio == NIL)
		throw EmptyTree();
	if (n == NIL)
		throw NullNode();
	if (spazio[n].sinistro != NIL)
		throw NodeExists();
	if (nNodi >= MAXLUNG)
		throw FullSize();
  else
    {
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].sinistro = q;
      spazio[q].sinistro = NIL;
      spazio[q].genitore = n;
      spazio[q].destro = NIL;
      spazio[q].nodiSucc = 1;
      this->modificaNodiSucc(q, '+');
      nNodi++;
    }
}

template <class T>
void Bin_treec<T>::ins_dx(Nodo n)
{
	if (inizio == NIL)
		throw EmptyTree();
	if (n == NIL)
		throw NullNode();
	if (spazio[n].destro != NIL)
		throw NodeExists();
	if (nNodi >= MAXLUNG)
		throw FullSize();
	else
    {
      Nodo q = libera;
      libera = spazio[libera].sinistro;
      spazio[n].destro = q;
      spazio[q].genitore = n;
      spazio[q].sinistro = NIL;
      spazio[q].destro = NIL;
      spazio[q].nodiSucc = 1;
      this->modificaNodiSucc(q, '+');
      nNodi++;
    }
}

template <class T>
void Bin_treec<T>::erase(Nodo n)
{
  if (n != NIL) {
      if (!sx_empty(n))
        erase(spazio[n].sinistro);
      if (!dx_empty(n))
        erase(spazio[n].destro);
      if (n != inizio) {
          Nodo p = parent(n);
          if (spazio[p].sinistro == n)
            spazio[p].sinistro = NIL;
          else
            spazio[p].destro = NIL;
        }
      else
        inizio = NIL;
      this->modificaNodiSucc(n, '-');
      nNodi--;
      spazio[n].sinistro = libera;
      libera = n;
    }
	else
		throw NullNode();
}

template <class T>
T Bin_treec<T>::read(Nodo n) const
{
  if (n != NIL)
    return (spazio[n].valore);
	else
		throw NullNode();
}

template <class T>
int Bin_treec<T>::nNodiSucc(Nodo n) const
{
  if (n != NIL)
    return (spazio[n].nodiSucc);
	else
		throw NullNode();
}

template <class T>
void Bin_treec<T>::write(Nodo n, value_type a)
{
  if (n != NIL)
    spazio[n].valore = a;
	else
		throw NullNode();
}

template <class T>
void Bin_treec<T>::eliminaPari(Nodo n){
	if (n != NIL){
		if (!sx_empty(n))
			this->eliminaPari(this->sx(n));
		if(!dx_empty(n))
			this->eliminaPari(this->dx(n));
		if((this->read(n) % 2) == 0)
			this->erase(n);
	}else
		throw NullNode();
}

template <class T>
void Bin_treec<T>::mutation(Bin_treec<T>& v, Nodo n, Bin_treec<T>& t, Nodo n2){
	Bin_treec<T> appoggio;
	appoggio.ins_root(n2);
	appoggio.write(appoggio.root(),t.read(n2));
	this->copia(appoggio, appoggio.root(), t, n2);
	if(!t.sx_empty(n2))
		t.erase(t.sx(n2));
	if(!t.dx_empty(n2))
		t.erase(t.dx(n2));
	t.write(n2, v.read(n));
	this->copia(t, n2, v, n);
	if(!v.sx_empty(n))
		this->erase(this->sx(n));
	if(!v.dx_empty(n))
		this->erase(this->dx(n));
	this->write(n, appoggio.read(appoggio.root()));
	this->copia(v, n, appoggio, appoggio.root());
}

template <class T>
void Bin_treec<T>::modificaNodiSucc(Nodo n, char c){
	Nodo aux;
	aux = n;
	while(spazio[aux].genitore!=NIL){
		aux=this->parent(aux);
		if(c=='+')
			spazio[aux].nodiSucc++;
		if(c=='-')
			spazio[aux].nodiSucc--;
	}
}

template <class T>
void Bin_treec<T>::copia(Bin_treec<T>& appoggio, Nodo n1, Bin_treec<T>& t, Nodo n2){
	if(!t.sx_empty(n2)){
		appoggio.ins_sx(n1);
		n1=appoggio.sx(n1);
		appoggio.write(n1, t.read(t.sx(n2)));
		this->copia(appoggio, n1, t, t.sx(n2));
	}
	if(!t.dx_empty(n2)){
		appoggio.ins_dx(n1);
		n1=appoggio.dx(n1);
		appoggio.write(n1, t.read(t.dx(n2)));
		this->copia(appoggio, n1, t, t.dx(n2));
	}
}

template <class T>
void Bin_treec<T>::arithmeticParseTree(string s){
	bool primo;
	Nodo n;
	int i;
	for(i=0; i<s.size(); i++){
		if(s[i]<'(' && s[i]>'9' && s[i]!=' ')
			throw ErrorInput();
	}
	i=0;
	if(s[i]=='('){
		this->ins_root(n);
		n=this->root();
		while(i<s.size()){
			if(s[i]=='('){
				this->ins_sx(n);
				n=this->sx(n);
				i++;
			}
			if(s[i]>'0' && s[i]<'9'){
				primo=true;
				while(s[i]>'0' && s[i]<'9'){
					if(primo){
						this->write(n, s.substr(i, 1));
						primo=false;
					}
					else{
						spazio[n].valore.append(s.substr(i, 1));
					}
					i++;
				}
				n=this->parent(n);
			}
			if(s[i]=='*'|| s[i]=='+'|| s[i]=='-'|| s[i]=='/'){
				this->write(n, s.substr(i, 1));
				this->ins_dx(n);
				n=this->dx(n);
				i++;
			}
			if(s[i]==')'){
				if(this->parent(n)!=NIL)
					n=this->parent(n);
				i++;
			}
		}
	}
	else
		throw ErrorInput();
}

#endif /* _Bin_treecC_H_ */
