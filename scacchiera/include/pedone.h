#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Scacchiera;

class Pedone : public Pezzo {
  public:
    //costruttore
    Pedone(Casella posizione, Colore colore);

    //metodo che ritorna il numero di mosse fatte prima di far fare il salto
    int get_mossa_salto() {return mossa_salto;}

    //reset mossa_salto
    void reset_mossa_salto() {mossa_salto = -1;}

    //metodo che sposta il pezzo
    int mossa(Casella posizione, Scacchiera& scacchiera) override; 


  private:
    //membro che salva il numero della mossa alla quale è stato fatto il doppio salto iniziale
    int mossa_salto = -1;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;

    
};
#endif // PEDONE_H