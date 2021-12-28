#ifndef SCACCHIERA_H
#define SCACCHIERA_H



#include <iostream>

#include "pezzi/pezzo.h"
#include "pezzi/alfiere.h"
#include "pezzi/re.h"
#include "pezzi/regina.h"
#include "pezzi/cavallo.h"
#include "pezzi/torre.h"
#include "pezzi/pedone.h"

class Scacchiera {
  public:
    static constexpr int COLONNE = 8;
    static constexpr int RIGHE = 8;

    Scacchiera();

    void stampa(); //stampa la scacchiera

    void mossa(Casella posizione_in, Casella posizione_fin); //controllo mossa fatto prima

    enum class Colonne {
      A ,B ,C, D, E, F, G, H
    };
  private:
    Pezzo* scacchiera[RIGHE][COLONNE]; //CONTROLLARE CHE SIA GIUSTO
};



#endif // SCACCHIERA_H