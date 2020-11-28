#ifndef _MATRICE
#define _MATRICE

	using namespace std;

	typedef double tipoelem;


class matrice {

  public:
  
    matrice(int, int); 					/* costruttore */
    
	matrice(const matrice&);					/* costruttore di copia */
    
	matrice& operator=(const matrice&);						/* operatore di assegnamento */
    
    ~matrice();  					 /* distruttore */
   
    tipoelem leggimatrice(int, int);
    
    void scrivimatrice(int, int, tipoelem);

	void prodottoScalare(double);

	matrice& trasposta(const matrice&);

	matrice& prodotto(matrice&);
    
  private:
    int righe;
    int colonne;
    tipoelem **elementi;

	tipoelem opInterne(matrice&, matrice&, int, int);
};

#endif /* _MATRICE */






/* Q: il metodo prodottoScalare deve cambiare i valori della matrice oppure deve returnare un'altra matrice? */
/* A: cambia solo i valori della matrice */

