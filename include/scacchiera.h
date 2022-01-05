#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <iostream>
#include <vector> 
#include <algorithm> //incluso per poter utilizzare l'algoritmo find 

#include "pezzo.h"
#include "alfiere.h"
#include "re.h"
#include "regina.h"
#include "cavallo.h"
#include "torre.h"
#include "pedone.h"

class Scacchiera {
  public:
    static constexpr int COLONNE = 8;
    static constexpr int RIGHE = 8;

    Scacchiera();

    void stampa(); //stampa la scacchiera

    bool mossa(Casella posizione_in, Casella posizione_fin); //controllo mossa fatto prima

    Pezzo* get_casella(Casella posizione);

    bool controllo_scacco(Pezzo::Colore colore);

    bool scaccomatto(Pezzo::Colore colore);

    int get_conta_mosse(){ return conta_mosse;} 

    //restituisce un vettore contentente le mosse possibili che può fare il pezzo che si
    //trova nella posizione da indicare "posizione_pezzo"
    std::vector<Casella> mosse_possibili(Casella posizione_pezzo);

    //restituisce una stringa da utilizzare nella mappa che contiene le varie disposizioni
    //della scacchiera durante la partita
    //pedone che può fare enpassant viene etichettato come F(P nero) e f(p bianco)
    //torre che può fare arrocco viene etichettata come G(T nera) e g(t bianca)
    //re che può fare arrocco viene etichettata come K(R nero) e k(r bianco)
    std::string stringa_per_mappa();
    
    //controllo che il giocatore colore non sia in stallo
    bool stallo(Pezzo::Colore colore);

  private:
    //matrice che contiene i puntatori ai singoli pezzi e rappresenta la scacchiera
    //posizione in matrice -> posizione scacchiera - 1
    Pezzo* scacchiera[RIGHE][COLONNE]; 

    //vector contenente i puntatori a tutti i pezzi ancora presenti nella scacchiera
    std::vector<Pezzo*> pezzi_neri;
    std::vector<Pezzo*> pezzi_bianchi;

    //puntatori ai due re (servono nello scacco)
    Pezzo* re_nero;
    Pezzo* re_bianco;

    //contatore delle mosse in cui non si muove un pedone ne si mangia un pezzo
    int conta_mosse;

    //metodo che verifica se è possibile promuovere qualche pedone e in caso sia possibile
    //lo fa di default a donna
    void promuovi();

};



#endif // SCACCHIERA_H