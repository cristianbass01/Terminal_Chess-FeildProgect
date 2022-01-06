#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Scacchiera;

class Pedone : public Pezzo {
  public:
    //costruttore
    Pedone(Casella posizione, Colore colore);

    //metodo che sposta il pezzo
    int mossa(Casella posizione, Scacchiera& scacchiera) override;

    //metodo che controlla se la mossa è valida (ANCHE controllo scacco)
    int simulazione_mossa(Casella posizione, Scacchiera& scacchiera) override; 

    int get_mossa_salto() {return mossa_salto;}
  private:
    //membro che salva il numero della mossa alla quale è stato fatto il doppio salto iniziale
    int mossa_salto = -1;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};
#endif // PEDONE_H