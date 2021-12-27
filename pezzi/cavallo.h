#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(int rig, int col, Colore color);
    void mossa(Casella posizione) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizone) override {return false;}
};

#endif // CAVALLO_H
