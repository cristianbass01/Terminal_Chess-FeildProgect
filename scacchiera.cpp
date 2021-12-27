#include "scacchiera.h"

Scacchiera::Scacchiera() {

  //inizializzazione tutti puntatori a nullptr
  for(int i = 0; i < RIGHE; i++) 
    for(int j = 0; j < COLONNE; j++) 
      scacchiera[i][j] = nullptr;


  //inizializzazione vari puntatori caselle bianche 
  scacchiera[0][0] = new Torre(0,0,Pezzo::Colore::bianco);
  scacchiera[0][7] = new Torre(0,7,Pezzo::Colore::bianco);

  scacchiera[0][1] = new Cavallo(0,1,Pezzo::Colore::bianco);
  scacchiera[0][6] = new Cavallo(0,6,Pezzo::Colore::bianco);

  scacchiera[0][2] = new Alfiere(0,2,Pezzo::Colore::bianco);
  scacchiera[0][5] = new Alfiere(0,5,Pezzo::Colore::bianco);

  scacchiera[0][3] = new Regina(0,3,Pezzo::Colore::bianco);
  scacchiera[0][4] = new Re(0,4,Pezzo::Colore::bianco);

  constexpr int RIGA_PEDONI_BIANCHI = 1;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_BIANCHI][i] = new Pedone(RIGA_PEDONI_BIANCHI, i, Pezzo::Colore::bianco);
  }

  //inizializzazione vari puntatori caselle nere
  scacchiera[7][0] = new Torre(7,0,Pezzo::Colore::nero);
  scacchiera[7][7] = new Torre(7,7,Pezzo::Colore::nero);

  scacchiera[7][1] = new Cavallo(7,1,Pezzo::Colore::nero);
  scacchiera[7][6] = new Cavallo(7,6,Pezzo::Colore::nero);

  scacchiera[7][2] = new Alfiere(7,2,Pezzo::Colore::nero);
  scacchiera[7][5] = new Alfiere(7,5,Pezzo::Colore::nero);

  scacchiera[7][3] = new Regina(7,3,Pezzo::Colore::nero);
  scacchiera[7][4] = new Re(7,4,Pezzo::Colore::nero);

  constexpr int RIGA_PEDONI_NERI = 6;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_NERI][i] = new Pedone(RIGA_PEDONI_NERI, i, Pezzo::Colore::nero);
  }
}

void Scacchiera::stampa() {
  for(int i = RIGHE - 1; i >= 0; i--) {
    std::cout<<i + 1<<' ';
    for(int j = COLONNE - 1; j >= 0; j--) {
      if((scacchiera[i][j] == nullptr))
        std::cout<<" ";
      else 
        std::cout<<(*scacchiera[i][j]).get_figura();
      }
      std::cout<<std::endl;
    }
  std::cout<<"  "<<"ABCDEFGH"<<std::endl;          
}

void Scacchiera::mossa(int riga_in, int colonna_in, int riga_fin, int colonna_fin) {
  if((*scacchiera[riga_in][colonna_in]).mossa_valida(riga_fin, colonna_fin)) {
    (*scacchiera[riga_in][colonna_in]).mossa(riga_fin, colonna_fin);
    scacchiera[riga_fin][colonna_fin] = scacchiera[riga_in][colonna_in];
    scacchiera[riga_in][colonna_in] = nullptr;
  }
  
}