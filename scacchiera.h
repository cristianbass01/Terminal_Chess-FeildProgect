#ifndef SCACCHIERA_H_
#define SCACCHIERA_H_

#include "pezzo.h"

#include <iostream>

class Scacchiera {
    public:
        static constexpr int COLONNE = 8;
        static constexpr int RIGHE = 8;

        Scacchiera();

        void stampa(); //stampa la scacchiera

        void mossa(int riga_in, int colonna_in, int riga_fin, int colonna_fin); //controllo mossa fatto prima

        class enum Colonne {
            char 'A','B','C','D','E','F','G','H'
        }
    private:
        pezzo[RIGHE][COLONNE] scacchiera; //CONTROLLARE CHE SIA GIUSTO
}

#endif // SCACCHIRA_H