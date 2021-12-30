#ifndef UMANO_H
#define UMANO_H

#include "scacchiera.h"
#include "giocatore.h"

class Umano : public Giocatore{
  private:

  public:
    Umano(Scacchiera*, Pezzo::Colore);
    void gioca();

    void combinazioni();
};

#endif // UMANO_H