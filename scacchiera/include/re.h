#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Scacchiera;

class Re : public Pezzo {
  public:
    //costruttore
    Re(Casella posizione, Colore colore);

    //metodo che dice se il pezzo ha almeno una mossa disponibile
    bool bloccato(Scacchiera& scacchiera);

    //metodi per controllare e modificare la variabile che controlla se l'arrocco è valido
    void invalido_arrocco(){ arrocco_valido = false; }
    bool get_arrocco_valido() { return arrocco_valido; }
    
  private:
    //variabile booleana che determina se il re non si è mai mosso, quindi può eseguire l'arrocco o meno
    bool arrocco_valido;

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;

};

#endif // RE_H