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
};

#endif // COMPUTER_H
