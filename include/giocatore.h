#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "scacchiera.h"

class Giocatore{
  protected:
    Scacchiera* scacchiera_;
    Pezzo::Colore colore_;
    Pezzo::Colore colore_avversario_;
    
  public:
    virtual void gioca() = 0; // metodo virtuale puro che fa eseguire una mossa al giocatore
    virtual bool ricevuta_richiesta_patta() = 0; // metodo virtuale puro che riceve e gestisce la richiesta di patta dell'avversario
    Pezzo::Colore get_colore() { return colore_; }
};

#endif // GIOCATORE_H
