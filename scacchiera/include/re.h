/*
  Bassotto Cristian 2000169
*/

#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Scacchiera;

class Re : public Pezzo {
  public:
    // Costruttore che riceve come argomenti la posizione attuale del re e il suo colore
    Re(Casella posizione, Colore colore);

    // metodo che restituisce true se il re non ha mosse possibili, false altrimenti
    bool bloccato(Scacchiera& scacchiera);

    // metodo che invalida l'arrocco
    void invalido_arrocco(){ arrocco_valido_ = false; }

    // metodo che restituisce true se l'arrocco è valido, false altrimenti
    bool get_arrocco_valido() const { return arrocco_valido_; }
    
  private:
    // variabile booleana che salva true se il re non si è mai mosso 
    // (arrocco valido per il re), false altrimenti
    bool arrocco_valido_{true};

    //metodo che controlla se la mossa è valida (SENZA controllo scacco)
    int mossa_valida(Casella posizione, Scacchiera& scacchiera) override;

};

#endif // RE_H