#include "TreeList.h"

int main(){

	TreeList<char> Tree;

	TreeList<char>::node n;
	Tree.insRoot(n);
	Tree.writeNode(Tree.root(),'a');

	Tree.insFirst(Tree.root(), 'b');
	Tree.insFirst(Tree.root(), 'c');

	n = Tree.root();
	n = Tree.firstChild(n);

	Tree.ins(n, 'd');

	n = Tree.root();
	n = Tree.firstChild(n);
	Tree.insFirst(n, 'e');
	Tree.insFirst(n, 'f');

	Tree.print();	

	cout<<Tree.profondita();

	n = Tree.root();
	n = Tree.firstChild(n);

	cout <<endl;
	cout<<"ciccionosità: : " << Tree.larghezza();
	cout <<endl;

	Tree.removeSubTree(n);


	Tree.print();

	cout<<Tree.profondita();

	Tree.insFirst(Tree.root(), 'c');
	n = Tree.root();
	n = Tree.firstChild(n);
	Tree.insFirst(n, 'e');
	Tree.insFirst(n, 'f');
	n = Tree.firstChild(n);
	Tree.insFirst(n, 'g');
	Tree.insFirst(n, 'h');
	n = Tree.root();
	n = Tree.firstChild(n);
	n = Tree.nextSibling(n);
	n = Tree.nextSibling(n);
	Tree.insFirst(n, 'i');

	Tree.print();	

	cout<<"profondità: " << Tree.profondita();
	cout <<endl;
	cout<<"ciccionosità: : " << Tree.larghezza();






	cout <<endl;
	cout <<endl;
	cout <<endl;
	cout <<endl;


	TreeList<string> Tree2;

	TreeList<string>::node n2;


	List_vector<string> v;
	List_vector<string>::position p;

	v.insert("0-1", v.begin());
	p=v.next(v.begin());
	v.insert("1-2",p);
	p=v.next(p);
	v.insert("1-3",p);
	p=v.next(p);
	v.insert("3-4",p);
	p=v.next(p);
	v.insert("0-5",p);

	Tree2.insLista(v);
	Tree2.print();


	return 0;
}
