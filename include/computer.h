#ifndef COMPUTER_H
#define COMPUTER_H

#include "giocatore.h"

class Computer : public Giocatore{
  private:


  public:
    // costruttore
    Computer(Scacchiera*, Pezzo::Colore);

    //chiede la mossa finche non ne esegue una
    void gioca();

    //riceve la richiesta di patta fatta dall'avversario
    bool ricevuta_richiesta_patta();

    //numero massimo di mosse nel caso di partita computer computer
    static constexpr int MAX_MOSSE = 250;
};

#endif // COMPUTER_H
