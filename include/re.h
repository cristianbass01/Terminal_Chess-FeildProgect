#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Scacchiera;

class Re : public Pezzo {
  public:
    //costruttore
    Re(Casella posizione, Colore colore);

    //metodo che sposta il pezzo
    int mossa(Casella posizione, Scacchiera& scacchiera) override; 

    //metodo che controlla se la mossa è valida (ANCHE controllo scacco)
    int simulazione_mossa(Casella posizione, Scacchiera& scacchiera) override; 

    void invalido_arrocco(){ arrocco_valido = false; }
    bool get_arrocco_valido() { return arrocco_valido; }
    
  private:
    bool arrocco_valido;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;

};

#endif // RE_H