/*


Scrivere un programma in grado di acquisire e rappresentare con un albero di analisi (parse tree) un'espressione aritmetica.
Fornire la funzione per la valutazione dell'espressione rappresentata da un albero.


*/
#include "Color_bin_tree.cpp"
#include "Bin_treec.h"
#include <iostream>

using namespace std;


int main(){
	Bin_treec<int> T, T2;
	typename Bin_treec<int>::Nodo n1, n2;

	T.ins_root(n1);
	T.write(T.root(),1);
	n1 = T.root();
	T.ins_sx(n1);
	T.ins_dx(n1);
	T.write(T.sx(n1),2);
	n1 = T.dx(n1);
	T.write(n1, 3);
	T.ins_dx(n1);
	T.write(T.dx(n1), 4);
	//T.print();
	cout << T;

	//T.eliminaPari(T.root());
	//T.print();
	cout << endl;
	T2.ins_root(n2);
	T2.write(T2.root(),1);
	n2 = T2.root();
	T2.ins_sx(n2);
	T2.ins_dx(n2);
	T2.write(T2.sx(n2),2);
	n2 = T2.dx(n2);
	T2.write(n2, 3);
	T2.ins_dx(n2);
	T2.write(T2.dx(n2), 4);
	cout << T2;


	cout << endl;
	cout << endl;

	T.mutation(T, T.dx(n1), T2, T2.root());
	cout << T;

	cout << endl;
	cout << endl;

	string s = "(3+(4*5))";
	Bin_treec<string> T3(s);
	cout << T3;

	cout << endl;
	cout << endl;








	int i;
	Color_bin_tree C;
	typename Bin_treec<int>::Nodo n3;

		C.ins_root(n3);
		C.write(C.root(),"rosso");  //livello 0
		n3 = C.root();
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"bianco");  //livello 1
		C.write(C.dx(n3),"bianco");  //livello 1
		n3=C.sx(n3);
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"rosso");  //livello 2
		C.write(C.dx(n3),"rosso");  //livello 2
		n3=C.sx(n3);
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"verde");  //livello 3
		C.write(C.dx(n3),"verde");  //livello 3
		n3=C.parent(n3);
		n3=C.dx(n3);
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"verde");  //livello 3
		C.write(C.dx(n3),"verde");  //livello 3
		n3 = C.root();
		n3=C.dx(n3);
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"verde");  //livello 2
		C.write(C.dx(n3),"verde");  //livello 2
		n3=C.dx(n3);
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"bianco");  //livello 3
		C.write(C.dx(n3),"bianco");  //livello 3
		n3=C.parent(n3);
		n3=C.sx(n3);
		C.ins_sx(n3);
		C.ins_dx(n3);
		C.write(C.sx(n3),"bianco");  //livello 3
		C.write(C.dx(n3),"bianco");  //livello 3


		cout << C;


		cout << endl;


		i=C.level_red();
		cout << i;
		cout << endl;
		cout << endl;

		i=C.green_leafs();
		cout << i;

}
