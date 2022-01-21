/*
  Cinel Giovanni 2000147
*/
#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "scacchiera.h"

class Giocatore{

  protected:
    
    Scacchiera* scacchiera_;
    Pezzo::Colore colore_;
    Pezzo::Colore colore_avversario_;
    
  public:

    //metodo virtuale puro che fa eseguire una mossa al giocatore
    virtual void gioca() = 0; 

    //metodo virtuale puro che riceve e gestisce la richiesta di patta dell'avversario
    virtual bool ricevuta_richiesta_patta() = 0; 

    //metodo virtuale puro
    virtual char scelta_promozione() = 0;

    //metodo che ritorna il colore del giocatore
    Pezzo::Colore get_colore() const { return colore_; }
};

#endif //GIOCATORE_H
