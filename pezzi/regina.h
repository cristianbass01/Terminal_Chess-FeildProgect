#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Regina : public Pezzo{
  public:
    Regina(Casella posizione, Colore colore);
    void mossa(Casella posizione_finale) override; //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione_finale) override;
};

#endif // REGINA_H