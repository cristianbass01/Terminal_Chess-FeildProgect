/*
  Nordio Gianluca 2007959
*/

#ifndef PEDONE_H
#define PEDONE_H

#include "pezzo.h"

class Scacchiera;

class Pedone : public Pezzo {
  public:
    //costruttore
    Pedone(Casella posizione, Colore colore);

    //metodo che ritorna il numero di mosse nella partita fatte prima di far fare il salto
    //ritorna -1 se non è stato fatto il salto
    int get_mossa_salto() const {return mossa_salto_;}

    //reset mossa_salto
    void reset_mossa_salto() {mossa_salto_ = -1;}

    //metodo che sposta il pezzo
    //posizione è la posizione finale in cui muoversi
    int mossa(Casella posizione, Scacchiera& scacchiera) override; 


  private:
    //membro che salva il numero della mossa alla quale è stato fatto il doppio salto iniziale
    //ha valore -1 se non è stato fatto
    int mossa_salto_ = -1;

  private:
    //metodo che controlla se la mossa è valida (SENZA fare il controllo dello scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;

    
};
#endif // PEDONE_H