#ifndef _NODOPVT_H
#define _NODOPVT_H
#include <iostream>

typedef int tipoelem;

class Nodo
  {
  public:
    
    Nodo();
    Nodo(tipoelem);
    ~Nodo();

    void setElemento(tipoelem);
    tipoelem getElemento() const;
    bool operator ==(Nodo &);

  private:
    tipoelem elemento;
  };

std::ostream & operator<<(std::ostream & out, const Nodo & nodo);
# endif // _NODOPVT_H
