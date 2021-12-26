#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include "./pezzi/pezzo.h"

#include <iostream>

class Scacchiera {
    public:
        static constexpr int COLONNE = 8;
        static constexpr int RIGHE = 8;

        Scacchiera();

        void stampa(); //stampa la scacchiera

        void mossa(int riga_in, int colonna_in, int riga_fin, int colonna_fin); //controllo mossa fatto prima

        enum class Colonne {
            A ,B ,C, D, E, F, G, H
        };
    private:
        Pezzo* scacchiera[RIGHE][COLONNE]; //CONTROLLARE CHE SIA GIUSTO
};

#endif // SCACCHIERA_H