
/*
L'insieme dei valori ammissibili per l'etichetta dei nodi dell'albero è il seguente {rosso, verde, bianco}.
*/
#include "Bin_treec.h"

using namespace std;

class Color_bin_tree : public Bin_treec<string>{ // @suppress("Class has a virtual method and non-virtual destructor")
    static const int NIL = -1;

public:
	//int green_leafs(); //: calcola e restituisce il numero di foglie il cui valore è "verde";

	void write(Nodo n, string a){
			if(n!=NIL && (a=="rosso" || a=="verde" || a=="bianco"))
				spazio[n].valore = a;
			else
				throw NullNode();
	}
	 //: calcola e restituisce il numero di nodi di livello pari il cui valore è "rosso" e che hanno almeno un figlio il cui valore è "bianco";
	int level_red(){
		int i=0;
		bool b=0;
		i=contaColore(root(), b, i);

		return i;
	}

	int green_leafs(){
		int i=0;
		i=contaVerde(root(), i);
		return i;
	}

private:
	int contaColore(Nodo n, bool b, int i){
		if(b==0 && read(n)=="rosso" && (read(sx(n))=="bianco" || read(dx(n))=="bianco")){
			i++;
			b=1;
		}
		else
			b=0;

		if(!sx_empty(n))
			i=contaColore(sx(n), b, i);
		if(!dx_empty(n))
			i=contaColore(dx(n), b, i);
		return i;
	}

	int contaVerde(Nodo n, int i){
		if(sx_empty(n) && dx_empty(n)){
			if(read(n)=="verde")
				i++;
		}
		else{
			i=contaVerde(sx(n), i);
			i=contaVerde(dx(n), i);
		}
		return i;
	}




};








