#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Scacchiera;

class Re : public Pezzo {
  public:
    Re(Casella posizione, Colore color);
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
    void invalido_arrocco(){ arrocco_valido = false; } 
    bool get_arrocco_valido() { return arrocco_valido; }
    
  private:
    bool arrocco_valido;
};

#endif // RE_H