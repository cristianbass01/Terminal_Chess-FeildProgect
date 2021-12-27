#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
<<<<<<< Updated upstream
    Cavallo(int rig, int col, Colore color);
    void mossa(Casella posizione) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizone) override {return false;}
=======
    Cavallo(Casella posizione, Colore colore);
    void mossa(Casella posizione) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override {return false;}
>>>>>>> Stashed changes
};

#endif // CAVALLO_H
