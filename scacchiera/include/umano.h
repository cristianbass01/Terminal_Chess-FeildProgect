/*
  Bassotto Cristian 2000169
*/
#ifndef UMANO_H
#define UMANO_H

#include "scacchiera.h"
#include "giocatore.h"

class Umano : public Giocatore{

  public:
    //costruttore
    Umano(Scacchiera*, Pezzo::Colore);

    //chiede la mossa finche non ne esegue una
    void gioca();

    //riceve la richiesta di patta fatta dall'avversario
    bool ricevuta_richiesta_patta();

    //stampa a video il formato delle possibili combinazioni
    void combinazioni();

    //richiede se si vuole eseguire la patta per posizioni ripetute
    bool richiesta_patta();
};

#endif // UMANO_H