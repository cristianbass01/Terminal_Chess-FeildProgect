#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Scacchiera;

class Re : public Pezzo {
  public:
    Re(Casella posizione, Colore color);
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // RE_H