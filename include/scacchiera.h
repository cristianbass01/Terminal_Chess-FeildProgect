#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <iostream>

#include "./../pezzi/include/pezzo.h"
#include "./../pezzi/include/alfiere.h"
#include "./../pezzi/include/re.h"
#include "./../pezzi/include/regina.h"
#include "./../pezzi/include/cavallo.h"
#include "./../pezzi/include/torre.h"
#include "./../pezzi/include/pedone.h"

class Scacchiera {
  public:
    static constexpr int COLONNE = 8;
    static constexpr int RIGHE = 8;

    Scacchiera();

    void stampa(); //stampa la scacchiera

    bool mossa(Casella posizione_in, Casella posizione_fin); //controllo mossa fatto prima

    Pezzo* get_casella(Casella posizione);

    bool controllo_scacco(Pezzo::Colore colore);

    enum class Colonne {
      A ,B ,C, D, E, F, G, H
    };
  private:
    Pezzo* scacchiera[RIGHE][COLONNE]; //CONTROLLARE CHE SIA GIUSTO

    Pezzo* Re_nero;
    Pezzo* Re_bianco;
};



#endif // SCACCHIERA_H