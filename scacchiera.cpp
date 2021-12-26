#include "scacchiera.h"

Scacchiera::Scacchiera() {
  for(int i = 0; i < COLONNE; i++) {

  }
}

void Scacchiera::stampa() {
    for(int i = RIGHE - 1; i >= 0; i--) {
        std::cout<<i + 1<<' ';
        for(int j = COLONNE - 1; j >= 0; j--) {
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