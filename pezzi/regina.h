#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Regina : public Pezzo{
  public:
    Regina(Casella posizione, Colore colore);
    void mossa(Casella posizione_fin) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione_fin) override {return false;}
};

#endif // REGINA_H