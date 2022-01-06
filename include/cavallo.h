#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Scacchiera;

class Cavallo : public Pezzo {
  public:
  
    //costruttore
    Cavallo(Casella posizione, Colore colore);

  private:
    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // CAVALLO_H
