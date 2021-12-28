#include "scacchiera.h"

Scacchiera::Scacchiera() {

  //inizializzazione tutti puntatori a nullptr
  for(int i = 0; i < RIGHE; i++) 
    for(int j = 0; j < COLONNE; j++) 
      scacchiera[i][j] = nullptr;



  constexpr int RIGA_PEDONI_BIANCHI = 1;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_BIANCHI][i] = new Pedone(Casella(RIGA_PEDONI_BIANCHI, i), Pezzo::Colore::bianco);
  }


  constexpr int RIGA_PEDONI_NERI = 6;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_NERI][i] = new Pedone(Casella(RIGA_PEDONI_NERI, i), Pezzo::Colore::nero);
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

void Scacchiera::mossa(Casella posizione_in, Casella posizione_fin) {
  //caso in cui nella posizione iniziale si trova nullptr
  if(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] == nullptr)
    throw Eccezione("[Eccezione::NessunPezzo] Nella casella selezionata non c'è nessun pezzo da muovere");

  Pezzo& pezzo_mosso = *(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()]);
  Pezzo& pezzo_mangiato = *(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()]);
  if(pezzo_mosso.mossa(posizione_fin, (*this).matrice())) {
    if(&pezzo_mangiato != nullptr) {
      delete &pezzo_mangiato;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
    }
    scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
    scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
  }
}

char** Scacchiera::matrice() {
  //inizializzo matrice di char
  char** temp = new char*[RIGHE];
  for (int i = 0; i < RIGHE; ++i)
    temp[i] = new char[COLONNE];
  
  for(int i = 0; i < RIGHE; i++) {
    for(int j = 0; j < COLONNE; j++) {
      if((scacchiera[i][j] == nullptr))
        temp[i][j] = ' ';
      else 
        temp[i][j] = (*scacchiera[i][j]).get_figura();
    }
  }

  /*
  for(int i = RIGHE - 1; i >= 0; i--) {
    for(int j = COLONNE - 1; j >= 0; j--) {
      if((scacchiera[i][j] == nullptr))
        temp[i][j] = ' ';
      else 
        temp[i][j] = (*scacchiera[i][j]).get_figura();
    }
  }
  */

  return temp;
  /*
    for (int i = 0; i < rows; ++i)
      delete [] matrix[i];
    delete [] matrix;
  */

}