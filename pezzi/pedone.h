#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Pedone : public Pezzo {
  public:
    Pedone(int rig, int col, Pezzo::Colore color);
    void mossa(int r, int c) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(int r, int c) override {return false;}
};
#endif // PEDONE_H