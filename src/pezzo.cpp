#include "./../include/scacchiera.h"

//metodo che sposta il pezzo
int Pezzo::mossa(Casella posizione, Scacchiera& scacchiera) { 
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;
  
  Casella tmp = posizione_;

  if(this->mossa_valida(posizione, scacchiera)) {
      posizione_ = posizione;
  }
  else
    return false;
  
  if(scacchiera.controllo_scacco(colore_)){
    posizione_ = tmp;
    return false;
  }
  return true;
}

//metodo virtuale che controlla se la mossa è valida (ANCHE controllo scacco)
int Pezzo::simulazione_mossa(Casella posizione, Scacchiera& scacchiera){
  Casella tmp = posizione_;

  if(this->mossa(posizione, scacchiera)){
    posizione_ = tmp;
    return true;
  }
  return false;
}

//funzione friend che esegue ovverride del operatore <<
std::ostream& operator<<(std::ostream& os, const Pezzo& temp) {
  //conversione di un char contenuto in temp.figura_ a stringa (accede a figura_ perchè friend)
  os << std::string(1,temp.figura_);
  return os;
}