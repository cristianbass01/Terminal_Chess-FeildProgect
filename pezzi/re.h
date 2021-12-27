#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo {
  public:
    Re(Casella posizione, Pezzo::Colore color);
    void mossa(Casella posizione) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override {return false;}
};

#endif // RE_H