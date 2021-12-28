#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo{
  public:
    Torre(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione_finale) override;
};

#endif // TORRE_H
