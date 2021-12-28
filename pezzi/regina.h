#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Regina : public Pezzo{
  public:
    Regina(Casella posizione, Colore colore);
    bool mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) override;
};

#endif // REGINA_H