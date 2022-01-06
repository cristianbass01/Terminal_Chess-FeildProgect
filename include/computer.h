#ifndef COMPUTER_H
#define COMPUTER_H

#include "giocatore.h"

class Computer : public Giocatore{
  private:


  public:
    // costruttore
    Computer(Scacchiera& scacc);

    //chiede la mossa finche non ne esegue una
    void gioca();

    //riceve la richiesta di patta fatta dall'avversario
    bool ricevuta_richiesta_patta();

    //richiede se si vuole eseguire la patta per posizioni ripetute
    bool richiesta_patta();
};

#endif // COMPUTER_H
