#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Scacchiera;

class Torre : public Pezzo{
  public:
  //costruttore
    Torre(Casella posizione, Colore colore);

    void invalido_arrocco(){ arrocco_valido = false; }
    bool get_arrocco_valido(){ return arrocco_valido; }
    
  private:
    bool arrocco_valido;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    bool mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // TORRE_H
