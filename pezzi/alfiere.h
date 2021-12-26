#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo {
  public:
    Alfiere(int rig, int col, Colore color);
    void mossa(int r, int c) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(int r, int c) override {return false;}
};

#endif // ALFIERE_H
