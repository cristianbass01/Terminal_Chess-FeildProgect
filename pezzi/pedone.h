#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo {
  public:
    Pedone(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione, char** scacchiera);
};
#endif // PEDONE_H