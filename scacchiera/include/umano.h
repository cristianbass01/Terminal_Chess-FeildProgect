/*
  Bassotto Cristian 2000169
*/
#ifndef UMANO_H
#define UMANO_H

#include "scacchiera.h"
#include "giocatore.h"

class Umano : public Giocatore{

  public:
    // costruttore che riceve come argoemnti la scacchiera 
    // in cui avverrà il gioco e il colore assegnatogli
    Umano(Scacchiera*, Pezzo::Colore);

    // chiede la mossa finchè non ne esegue una
    void gioca() override;

    // riceve la richiesta di patta fatta dall'avversario e
    // restituisce true se è d'accordo sulla patta, false altrimenti
    bool ricevuta_richiesta_patta();

    // stampa a video il formato delle possibili combinazioni
    void combinazioni();

    // richiede se si vuole eseguire la patta per posizioni ripetute
    // restituisce true se il giocatore umano acconsente, false altrimenti
    bool richiesta_patta();

    // metodo che chiede al giocatore con che pezzo voglio eseguire la promozione sul pedone
    char scelta_promozione() override;

    // metodo che data una casella stampa tutte le mosse possibili che può fare il pezzo in quella casella
    void mosse_lecite(Casella pos_pezzo);
};

#endif // UMANO_H