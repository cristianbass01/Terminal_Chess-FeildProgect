#ifndef COMPUTER_H
#define COMPUTER_H

#include "giocatore.h"

class Computer : public Giocatore{
  private:


  public:
    Computer(Scacchiera& scacc);
    void gioca();
};

#endif // COMPUTER_H
