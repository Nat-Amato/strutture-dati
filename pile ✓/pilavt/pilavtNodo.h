#ifndef _PILAVTNODO_H
#define _PILAVTNODO_H
#include "nodoPvt.h"

const int MAXLUNGH=100;

class Pila
  {
    friend void stampaPila(Pila & L);

  public:
    Pila();
    ~Pila();
    void creaPila();
    bool pilaVuota() const;
    tipoelem leggiPila() const;
    void fuoriPila();
    void inPila(tipoelem);
  private:
    Nodo elementi[MAXLUNGH];
    int testa;
  };
#endif // _PILAVTNODO_H