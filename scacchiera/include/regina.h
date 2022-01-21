/*
  Nordio Gianluca 2007959
*/

#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Scacchiera;

class Regina : public Pezzo{
  public:
  //costruttore
    Regina(Casella posizione, Colore colore);

  private:
    //metodo che controlla se la mossa è valida (SENZA fare il controllo dello scacco)
    //posizione è la posizione finale in cui muoversi
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // REGINA_H