#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo {
  public:
    Re(Casella posizione, Colore color);
    bool mossa_valida(Casella posizione) override;
};

#endif // RE_H