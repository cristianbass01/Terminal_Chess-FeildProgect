#include "./../include/pezzo.h"

bool Pezzo::mossa(Casella posizione, Scacchiera& scacchiera) { //metodo che sposta il pezzo
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;
  try
  {
    if(mossa_valida(posizione, scacchiera)) {
      posizione_ = posizione;
      return true;
    }
  }
  catch(Eccezione e)
  {
    if((e.errore()).compare("[Eccezione::EnPassant]") == 0) //gestisce l'en passant 
      posizione_ = posizione;
    throw Eccezione("[Eccezione::EnPassant]");

  }
  return false;
}

//funzione friend che esegue ovverride del operatore <<
std::ostream& operator<<(std::ostream& os, const Pezzo& temp) {
  //conversione di un char contenuto in temp.figura_ a stringa (accede a figura_ perchè friend)
  std::string s = std::string(1,temp.figura_);

  return os<<s;
}