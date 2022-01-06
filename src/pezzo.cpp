#include "./../include/scacchiera.h"

//metodo che sposta il pezzo
int Pezzo::mossa(Casella posizione, Scacchiera& scacchiera) { 
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;
  
  Casella tmp = posizione_;

  int mossa_valida = this->mossa_valida(posizione, scacchiera);
  if(mossa_valida) {
      posizione_ = posizione;
  }
  else if(mossa_valida == EN_PASSANT  || mossa_valida == ARROCCO){
    // gestione en passant, salto del pedone e arrocco
    posizione_ = posizione;
  }
  
  //controllo scacco
  if(scacchiera.controllo_scacco(colore_)){
    posizione_ = tmp;
    return false;
  }

  //se non da scacco do il controllo di nuovo alla funzione chiamante
  return mossa_valida;
}

//metodo virtuale che controlla se la mossa è valida (ANCHE controllo scacco)
int Pezzo::simulazione_mossa(Casella posizione, Scacchiera& scacchiera){
  Casella tmp = posizione_;

  int mossa = this->mossa(posizione, scacchiera);

  //se la mossa era valida e ha spostato i pezzi li faccio tornare alla posizione iniziale
  if(mossa || mossa == EN_PASSANT || mossa == ARROCCO){
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