#include "./../include/scacchiera.h"
#include "./../include/pezzo.h"

//metodo che sposta il pezzo
int Pezzo::mossa(Casella posizione, Scacchiera& scacchiera) { 
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;

  int mossa_valida = this->mossa_valida(posizione, scacchiera);
  if(mossa_valida == true || mossa_valida == EN_PASSANT  || mossa_valida == ARROCCO) {
      posizione_ = posizione;
  }

  //se non da scacco do il controllo di nuovo alla funzione chiamante
  return mossa_valida;
}

//funzione friend che esegue ovverride del operatore <<
std::ostream& operator<<(std::ostream& os, const Pezzo& temp) {
  //conversione di un char contenuto in temp.figura_ a stringa (accede a figura_ perchè friend)
  os << std::string(1,temp.figura_);
  return os;
}