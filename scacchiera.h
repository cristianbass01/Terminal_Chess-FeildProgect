#ifndef SCACCHIERA_H
#define SCACCHIERA_H

class Scacchiera;

#include "pezzi/pezzo.h"
#include "pezzi/pedone.h"

#include <iostream>

class Scacchiera {
  public:
    static constexpr int COLONNE = 8;
    static constexpr int RIGHE = 8;

    Scacchiera();

    void stampa(); //stampa la scacchiera

    char** matrice();

    void mossa(Casella posizione_in, Casella posizione_fin); //controllo mossa fatto prima

  private:
    Pezzo* scacchiera[RIGHE][COLONNE]; //CONTROLLARE CHE SIA GIUSTO
};

#endif // SCACCHIERA_H