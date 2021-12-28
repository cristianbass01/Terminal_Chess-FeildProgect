#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Scacchiera;

class Alfiere : public Pezzo {
  public:
    Alfiere(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // ALFIERE_H
