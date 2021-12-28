#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // CAVALLO_H
