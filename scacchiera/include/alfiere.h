/*
  Cinel Giovanni 2000147
*/

#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Scacchiera;

class Alfiere : public Pezzo {

  public:

    //costruttore
    Alfiere(Casella posizione, Colore colore);

  private:
  
    //metodo che controlla se la mossa è valida 
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif //ALFIERE_H
