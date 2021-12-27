#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(Casella posizione, Colore colore);
    void mossa(Casella posizione) override; //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override;
};

#endif // CAVALLO_H
