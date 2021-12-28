#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Scacchiera;

class Pedone : public Pezzo {
  public:
    Pedone(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};
#endif // PEDONE_H