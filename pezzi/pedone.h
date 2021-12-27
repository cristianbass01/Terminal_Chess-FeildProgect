#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo {
  public:
    Pedone(Casella posizione, Colore colore);
    void mossa(Casella posizione) override; //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override;
};
#endif // PEDONE_H