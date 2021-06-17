#ifndef TREELIST_H
#define TREELIST_H

#include "list_vector.h"
#include "Tree.h"
#include <string>


#define MAXNODES 100

template<class I>
class TreeList : public Tree<I, int> {
 public:

	typedef I item;
	typedef int node;

	// Costruttori e distruttore
	TreeList(){
		create();
	};

	virtual void create () ;
	virtual bool empty () const ;
	virtual void insRoot (node) ;
	virtual node root () const ;
	virtual node parent (node) const ;
	virtual bool leaf (node) const ;
	virtual node firstChild (node) const ;
	virtual bool lastSibling (node) const ;
	virtual node nextSibling (node) const ;
	// DA IMPLEMENTARE
	//	virtual void insFirstSubTree (node, TreeList &) ;
	//	virtual void insSubTree (node, TreeList &) ;
	virtual void removeSubTree (node) ;

	void insFirst(node, item);
	void ins(node, item);

	int profondita();

	int larghezza();

	void insLista(List_vector<string>);

	 node cerca(item);

	virtual void writeNode (node, item) ;
	virtual item readNode (node) const ;

	void print() const;

 private:
	struct Record {
		item e;
		bool used;
		int profondita;
		List_vector<int> childs; // lista delle posizioni dei figli di un nodo
	};
	typedef List_vector<int>::position position_list;
 
	Record nodes[MAXNODES];
	node _root;
	int numNodes;
	int spessore[MAXNODES]; // rappresenta il numero di nodi in un livello


};


template <class I>
void TreeList<I>::print() const{
	cout << "\n{";
	for (int i=0; i < MAXNODES;i++){
		if (nodes[i].used==true){
			cout << "\n  " << readNode(i) << ":  ";
			if (!leaf(i)){
				position_list child = nodes[i].childs.begin();					
				while (!nodes[i].childs.end(child)){
					cout << readNode(nodes[i].childs.read(child)) << " "; 
					child = nodes[i].childs.next(child);
				}
			}
		}

	}
	cout << "\n}\n";
}

template <class I>
void TreeList<I>::create(){
	numNodes = 0;
	for (int i=0; i< MAXNODES;i++){
		nodes[i].used = false;
		nodes[i].profondita=0;
		nodes[i].childs.create();
		spessore[i]=0;
	}
}

template <class I>
bool TreeList<I>::empty() const{
	return(numNodes == 0);
}

template <class I>
void TreeList<I>::insRoot (node n){
	if (empty()){
		_root = 0;
		nodes[0].used = true;
		spessore[0]=1;
		numNodes++;
	}
}

template <class I>
typename TreeList<I>::node TreeList<I>::root () const{
	return _root;
}

template <class I>
typename TreeList<I>::node TreeList<I>::parent (node n) const{ // @suppress("No return")
	position_list child;		
	int p;
	for (int i=0; i < MAXNODES; i++){
		if (!nodes[i].childs.empty()){
			child = nodes[i].childs.begin();
			bool found = false;
			while (!nodes[i].childs.end(child) && !found){
				if (nodes[i].childs.read(child) == n){
					found = true;
					p = i;
				}
				child = nodes[i].childs.next(child);
			}
			if (found)
				return(i);
		}
	}
}

template <class I>
bool TreeList<I>::leaf(node n) const{
	return(nodes[n].childs.empty());
}

template <class I>
typename TreeList<I>::node TreeList<I>::firstChild (node n) const{ // @suppress("No return")
	if (!leaf(n)){
		return(nodes[n].childs.read(nodes[n].childs.begin()));
	}
}

template <class I>
bool TreeList<I>::lastSibling (node n) const {
	position_list c;
	node p = parent(n);
	c = nodes[p].childs.begin();
	while (!nodes[p].childs.end(c))
		c = nodes[p].childs.next(c);
	return (n == nodes[p].childs.read(c));
}

template <class I>
typename TreeList<I>::node TreeList<I>::nextSibling (node n) const{ // @suppress("No return")
	if (!lastSibling(n)){
		position_list c;
		node p = parent(n);
		c = nodes[p].childs.begin();
		while (!nodes[p].childs.end(c)){
			if (nodes[p].childs.read(c) == n)
				return (nodes[p].childs.read(nodes[p].childs.next(c)));
			c = nodes[p].childs.next(c);
		}
	}
}


// inserisce un node come firstChild di n
template <class I>
void TreeList<I>::insFirst(node n, item el){
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		nodes[k].profondita=nodes[n].profondita+1;
		nodes[n].childs.insert(k, nodes[n].childs.begin());
		spessore[nodes[k].profondita]++;
	}
}

// inserisce un node come fratello di n
template <class I>
void TreeList<I>::ins(node n, item el){
	// cerca una posizione libera
	int k;
	for (k=0; k < MAXNODES && nodes[k].used == true; k++);
	if (k<MAXNODES){
		nodes[k].used = true;
		nodes[k].e = el;
		spessore[nodes[n].profondita]++;
		node p = parent(n);
		position_list child = nodes[p].childs.begin();
		bool found = false;
		while (!nodes[p].childs.end(child) && !found){
			if (nodes[p].childs.read(child) == n)
					found = true;
			child = nodes[p].childs.next(child);
		}
		nodes[p].childs.insert(k, child);
	}
}

template <class I>
int TreeList<I>::profondita(){
	int profMax=0;
	for(int i=0; i<MAXNODES; i++){
		if(nodes[i].used==true && leaf(i) && nodes[i].profondita>profMax)
			profMax=nodes[i].profondita;
	}
	return profMax;
}

template <class I>
int TreeList<I>::larghezza(){
	int spessoreMax=0;
	for(int i=0; spessore[i]!=0; i++){
		if(spessoreMax<spessore[i])
			spessoreMax=spessore[i];
	}
	return spessoreMax;
}

template <class I>
void TreeList<I>::insLista(List_vector<string> v){
	node n;
	List_vector<string>::position p;
	string prima, seconda;
	prima=v.read(v.begin()).substr(0,(v.read(v.begin()).find_first_of("-")));
	seconda=v.read(v.begin()).substr((v.read(v.begin()).find_first_of("-")+1));
	insRoot(n);
	writeNode(root(),prima);
	n = root();
	insFirst(n, seconda);
	p=v.begin();
	p=v.next(p);
	while(!v.end(p)){
		prima=v.read(p).substr(0,(v.read(p).find_first_of("-")));
		seconda=v.read(p).substr((v.read(p).find_first_of("-")+1));
		n=cerca(prima);
		insFirst(n, seconda);
		p=v.next(p);
	}
}


template <class I>
typename TreeList<I>::node TreeList<I>::cerca(item i){
	node n;
	bool trovato=false;
	for(int j=0; j<MAXNODES && nodes[j].used && !trovato; j++){
		if(nodes[j].e==i){
			trovato=true;
			n=j;
		}
	}
	return n;
}



template <class I>
void TreeList<I>::removeSubTree (node n){

	position_list c;
	if (!leaf(n)){
		while (!nodes[n].childs.empty()){
			removeSubTree(nodes[n].childs.read(nodes[n].childs.begin()));
		}
	}
	node p = parent(n);
	c = nodes[p].childs.begin();	
	while(nodes[p].childs.read(c) != n)
		c = nodes[p].childs.next(c);
	nodes[p].childs.erase(c);
	nodes[n].used = false;
	spessore[nodes[n].profondita]--;
}


template <class I>
void TreeList<I>::writeNode (node n, item el){
	nodes[n].e = el;
}

template <class I>
typename TreeList<I>::item TreeList<I>::readNode (node n) const{
	return(nodes[n].e);
}

#endif
