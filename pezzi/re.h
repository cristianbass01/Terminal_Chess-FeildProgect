#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo {
  public:
<<<<<<< Updated upstream
    Re(Casella posizione, Pezzo::Colore colore);
    void mossa(Casella posizione) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override {return false;}
=======
    Re(Casella posizione, Pezzo::Colore color);
    void mossa(Casella posizione) override; //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(Casella posizione) override;
>>>>>>> Stashed changes
};

#endif // RE_H