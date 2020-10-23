#ifndef _MATRICE
#define _MATRICE

using namespace std;

definire il tipo tipoelem

	typedef double tipoelem;

definire la classe matrice

class matrice {

  public:
  
    matrice(int, int); 					/* costruttore */
    
    matrice(const matrice& M){
	matrice(M.righe, M.colonne);
	//...	
    }							/* costruttore di copia */  
    
    matrice& operator=(const matrice& M){
    	//come per il costruttore di copia
	//...
    	return *this;
    }							/* operatore di assegnamento */
    
    ~matrice();  					 /* distruttore */
    
    tipoelem leggimatrice(int, int);
    
    void scrivimatrice(int, int, tipoelem);
    
  private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

#endif /* _MATRICE */
