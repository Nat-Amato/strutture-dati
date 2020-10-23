#ifndef _MATRICE
#define _MATRICE

definire il tipo tipoelem

	typedef double tipoelem;

definire la classe matrice

class matrice {
  public:
    matrice(int, int); /* costruttore */
    tipoelem leggimatrice(int, int);
    void scrivimatrice(int, int, tipoelem);
  private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

#endif /* _MATRICE */
