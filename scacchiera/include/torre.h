#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Scacchiera;

class Torre : public Pezzo{
  public:
  //costruttore
    Torre(Casella posizione, Colore colore);

    //metodi per controllare e modificare la variabile che controlla se l'arrocco è valido
    void invalido_arrocco(){ arrocco_valido = false; }
    bool get_arrocco_valido(){ return arrocco_valido; }
    
  private:
    //variabile booleana che determina se il cavallo non si è mai mosso, quindi può eseguire l'arrocco o meno
    bool arrocco_valido;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;
};

#endif // TORRE_H
