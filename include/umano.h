#ifndef UMANO_H
#define UMANO_H

#include "scacchiera.h"
#include "giocatore.h"

class Umano : public Giocatore{
  private:

  public:
    Umano(Scacchiera*, Pezzo::Colore);
    void gioca();
    bool ricevuta_richiesta_patta();
    void combinazioni();
    bool richiesta_patta();
};

#endif // UMANO_H