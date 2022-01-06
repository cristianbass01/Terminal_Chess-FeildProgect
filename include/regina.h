#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Scacchiera;

class Regina : public Pezzo{
  public:
  //costruttore
    Regina(Casella posizione, Colore colore);

  private:
    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // REGINA_H