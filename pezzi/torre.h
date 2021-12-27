#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo{
  public:
    Torre(int rig, int col, Colore color);
    void mossa(int r, int c) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(int r, int c) override;
};

#endif // TORRE_H
