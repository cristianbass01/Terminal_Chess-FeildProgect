#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Scacchiera;

class Torre : public Pezzo{
  public:
    Torre(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) override;
    void invalido_arrocco(){ arrocco_valido = false; }
    bool get_arrocco_valido(){ return arrocco_valido; }
    
  private:
    bool arrocco_valido;
};

#endif // TORRE_H
