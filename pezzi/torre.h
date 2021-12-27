#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo{
  public:
    Torre(Casella posizione, Colore color);
    void mossa(Casella posizione_fin) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione_fin) override;
};

#endif // TORRE_H
