#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <iostream>
#include <vector> //incluso per utilizzare vector in pezzi_bianchi e pezzi_neri
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
};



#endif // SCACCHIERA_H