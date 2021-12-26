#include "scacchiera.h"

Scacchiera::Scacchiera() {
  
}

void Scacchiera::stampa() {
    for(int i = 0; i < RIGHE; i++) {
        std::cout<<RIGHE-i<<' ';
        for(int j = 0; j < COLONNE; j++) {
            if((scacchiera[i][j]))
                std::cout<<" ";
            else 
                std::cout<<(*scacchiera[i][j]).get_figura();
        }
        std::cout<<std::endl;
    }
    std::cout<<"  "<<"ABCDEFGH"<<std::endl;
            
}

void Scacchiera::mossa(int riga_in, int colonna_in, int riga_fin, int colonna_fin) {
  scacchiera[riga_fin][colonna_fin] = scacchiera[riga_in][colonna_in];
  scacchiera[riga_in][colonna_in] = nullptr;
}