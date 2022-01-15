/*
  Bassotto Cristian 2000169
*/

#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Scacchiera;

class Torre : public Pezzo{
  public:
    //costruttore
    Torre(Casella posizione, Colore colore);

    //metodo che invalida l'arrocco
    void invalido_arrocco(){ arrocco_valido_ = false; }

    //metodo che restituisce true se l'arrocco è valido, false altrimenti
    bool get_arrocco_valido() const { return arrocco_valido_; }
    
  private:
    //variabile booleana che salva true se il cavallo non si è mai mosso 
    //(arrocco valido per il cavallo), false altrimenti
    bool arrocco_valido_;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // TORRE_H
