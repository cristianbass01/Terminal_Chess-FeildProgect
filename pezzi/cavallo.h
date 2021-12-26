#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(int rig, int col, Colore color);
    void mossa(int r, int c) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(int r, int c) override {return false;}
};

#endif // CAVALLO_H
