#ifndef GRAFOLIST_H
#define GRAFOLIST_H

#include "Grafo.h"
#include "list_vector.h"


class NodoG{
 public:
  NodoG(int i){
    nodoId = i;
  }
  NodoG(){
  }
  int getId(){ return nodoId; }
  void setId(int id) {nodoId = id;}
 private:
  int nodoId;
};


template<class P>
class InfoArco {
 public:
  P peso;
  NodoG _to;
};


template<class E, class P> 
  class InfoNodo {
 public:
  E   etichetta;
  bool vuoto;
  void* info;
  List_vector<InfoArco<P> > archi;
  List_vector<NodoG> archIn;
    
  InfoNodo(){ 
    info = 0; 
    vuoto = true; 
  }
};



template<class E, class P>
  class GrafoList : public Grafo<E, P, NodoG > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
    typedef typename Grafo_::ListaNodo ListaNodo;
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoList(int);
    ~GrafoList();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
    //    bool esisteNodo(Nodo);
    //    bool esisteArco(Arco);
    ListaNodo Adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;
    int inDegree(Nodo) const; //restituisce il numero di archi entranti in Nodo
    int outDegree(Nodo) const; //restituisce il numero di archi uscenti in Nodo
    double meanOutDegree(); // media degli archi uscenti(dei nodi) del grafo
    void findPath(Nodo, Nodo);

    int numNodi(){
      return nodi;
    };
    int numArchi(){
      return archi;
    };


 private:
    ListaNodo cammini(Nodo, Nodo, int, ListaNodo&);
    InfoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
    int archi;
};


template<class E, class P>
  GrafoList<E, P>::GrafoList(int _dimensione){
  dimensione = _dimensione;
  nodi = 0;
  archi = 0;
  matrice = new InfoNodo<E,P>[dimensione];
  for (int i=0; i<dimensione; i++){
    matrice[i].archi.create();
    matrice[i].archIn.create();
  }
}

template<class E, class P>
  GrafoList<E, P>::~GrafoList() {
  delete [] matrice;
}

template<class E, class P>
  bool GrafoList<E, P>::vuoto() const {
  return (nodi == 0);
}

template<class E, class P>
  void GrafoList<E, P>::insNodo(Nodo& N) {
  int n = 0;
  if (nodi < dimensione){
    while (matrice[n].vuoto == false)
      n++;
    nodi++;
    matrice[n].vuoto = false;
  }
  N.setId(n);
}

template<class E, class P>
  void GrafoList<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
  InfoArco<P> I;
  I.peso = peso;
  I._to = n2;
  matrice[n2.getId()].archIn.insert(n1, matrice[n2.getId()].archIn.begin());
  matrice[n1.getId()].archi.insert(I, matrice[n1.getId()].archi.begin());
  archi++;
}


template<class E, class P>
  void GrafoList<E, P>::cancNodo(Nodo n) {
	typename List_vector<InfoArco<P>>::position p;
	p = matrice[n.getId()].archi.begin();
	typename List_vector<NodoG>::position p2;
	p2 = matrice[n.getId()].archIn.begin();
  // ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
  bool canc = false;
  int i;
  for (i=0; i < dimensione && !canc; i++){

    if (!matrice[n.getId()].archi.empty()) {

      cancArco(n,matrice[n.getId()].archi.read(p)._to);

    }
    else
    	canc=true;
  	if(!matrice[n.getId()].archIn.empty()){
  		canc=false;
  		cancArco(matrice[n.getId()].archIn.read(p2), n);
  		matrice[n.getId()].archIn.erase(p2);
  	}
  	else{
  		canc=true;
  	}
  }

  if (canc){
	  nodi--;

    // la lista  matrice[n.getId()].archi è vuota;
    matrice[n.getId()].vuoto = true;
  }
}

template<class E, class P>
  void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2){
	typename List_vector<InfoArco<P>>::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else 
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato)
		matrice[n1.getId()].archi.erase(p);
  archi--;
}

template<class E, class P>
  typename GrafoList<E, P>::ListaNodo GrafoList<E, P>::Adiacenti(Nodo n) const{
  ListaNodo list;
  typename List_vector<Nodo>::position p;
  typename List_vector<InfoArco<P>>::position p2;
  p=matrice[n.getId()].archIn.begin();
  while(!matrice[n.getId()].archIn.end(p)){
	  list.insert(matrice[n.getId()].archIn.read(p), p);
	  p=matrice[n.getId()].archIn.next(p);
  }

  p2=matrice[n.getId()].archi.begin();
  while(!matrice[n.getId()].archi.end(p2)){
	  list.insert(matrice[n.getId()].archi.read(p2)._to, p2);
	  	  p2=matrice[n.getId()].archi.next(p2);
  }
  return list;
}

template<class E, class P>
  typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::list_nodi() const {
  ListaNodi list;
  for (int i = 0; i < dimensione; i++)
    if (!matrice[i].vuoto) 
      list.insert(new NodoG(i), list.begin());
  return list;
}

template<class E, class P>
  E GrafoList<E, P>::leggiEtichetta(Nodo n) const {
  return matrice[n.getId()].etichetta;
}

template<class E, class P>
  void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta) {
  matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
  P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else 
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato)
		return matrice[n1.getId()].archi.read(p).peso;
}

template<class E, class P>
  void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else 
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato){
		InfoArco<P> I;
		I.peso = peso;
		I._to = n2;
		matrice[n1.getId()].archi.write(I,p);
	}
}

template<class E, class P>
  int GrafoList<E, P>::inDegree(Nodo n) const {
return matrice[n.getId()].archIn.size();
}


template<class E, class P>
  int GrafoList<E, P>::outDegree(Nodo n) const {
return matrice[n.getId()].archi.size();
}

template<class E, class P>
  double GrafoList<E, P>:: meanOutDegree(){
	double n=0;
	double m=0;
	for(int i=0; i < dimensione; i++){
		if(!matrice[i].vuoto){
			n+=matrice[i].archi.size();
			m++;
		}
	}
return n/m;
}

template<class E, class P>
  void GrafoList<E, P>:: findPath(Nodo inizio, Nodo fine){
	int archiVisitati=0;
	int i=0;
	ListaNodo lista;
	typename List_vector<Nodo>::position p;
	p=lista.begin();
	lista=cammini(inizio, fine, archiVisitati, lista);
	if(lista.empty())
		cout<<"Cammino non possibile";
	else{
		while(!lista.end(p)){
			p=lista.next(p);
			i++;
		}
		p=lista.previous(p);
		while(i>0){
			cout << matrice[lista.read(p).getId()].etichetta;
			if(i>1)
				cout << " --> ";
			p=lista.previous(p);
			i--;
		}
	}
}

template<class E, class P>
  typename GrafoList<E, P>::ListaNodo GrafoList<E, P>::cammini(Nodo inizio, Nodo fine, int archiVisitati, ListaNodo &lista){
	if(archiVisitati<numArchi()){
		if(!matrice[inizio.getId()].archi.empty()){
			typename List_vector<InfoArco<P> >::position p;
			typename List_vector<Nodo>::position p2;
			p=matrice[inizio.getId()].archi.begin();
			p2=lista.begin();
			while(!matrice[inizio.getId()].archi.end(p)){
				if(matrice[matrice[inizio.getId()].archi.read(p)._to.getId()].etichetta==matrice[fine.getId()].etichetta){
					lista.insert(inizio, p2);
					lista.insert(fine, p2);
					return lista;
				}
				else
					p=matrice[inizio.getId()].archi.next(p);
			}
			p=matrice[inizio.getId()].archi.begin();
			bool finale=false;
			while(!matrice[inizio.getId()].archi.end(p) && !finale){
				archiVisitati++;
				Nodo n;
				n=matrice[inizio.getId()].archi.read(p)._to;
				lista.insert(inizio, p2);
				lista=cammini(n, fine, archiVisitati, lista);
				if(matrice[lista.read(p2).getId()].etichetta==matrice[fine.getId()].etichetta && lista.size()>2)
					finale=true;
				if(!finale)
					lista.erase(p2);
				p=matrice[inizio.getId()].archi.next(p);
			}
		}
	}
	return lista;
}
#endif
