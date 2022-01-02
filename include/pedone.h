#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Scacchiera;

class Pedone : public Pezzo {
  public:
    Pedone(Casella posizione, Colore colore);
    bool mossa(Casella posizione, Scacchiera& scacchiera) override;
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
    bool en_passant_valid_;

};
#endif // PEDONE_H