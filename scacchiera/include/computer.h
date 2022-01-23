/*
  Cinel Giovanni 2000147
*/

#ifndef COMPUTER_H
#define COMPUTER_H

#include "giocatore.h"

class Computer : public Giocatore{

  public:

    //costruttore
    Computer(Scacchiera*, Pezzo::Colore);

    //metodo che gestisce la richiesta della mossa finche non viene passata una mossa valida
    void gioca();

    //metodo che gestisce la richiesta di patta fatta dall'avversario
    bool ricevuta_richiesta_patta();

    // metodo che chiede al giocatore con che pezzo voglio eseguire la promozione sul pedone
    char scelta_promozione() override;

    //numero massimo di mosse nel caso di partita computer vs computer
    static constexpr int MAX_MOSSE = 300;
};

#endif // COMPUTER_H
