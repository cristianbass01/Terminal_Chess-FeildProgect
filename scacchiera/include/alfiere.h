#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Scacchiera;

class Alfiere : public Pezzo {
  public:
    //costruttore
    Alfiere(Casella posizione, Colore colore);

  private:
    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // ALFIERE_H