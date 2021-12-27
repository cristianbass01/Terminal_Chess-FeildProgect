#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo {
  public:
    Alfiere(Casella posizione, Colore colore);
    void mossa(Casella posizione) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override {return false;}
};

#endif // ALFIERE_H
