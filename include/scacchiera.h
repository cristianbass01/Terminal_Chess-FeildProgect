#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <iostream>

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
    
  private:
    Pezzo* scacchiera[RIGHE][COLONNE]; //CONTROLLARE CHE SIA GIUSTO

    Pezzo* Re_nero;
    Pezzo* Re_bianco;
};



#endif // SCACCHIERA_H