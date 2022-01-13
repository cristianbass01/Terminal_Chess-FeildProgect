/*
  Cinel Giovanni 2000147
*/

#include "./../include/scacchiera.h"
#include "./../include/pezzo.h"

//metodo che sposta il pezzo
int Pezzo::mossa(Casella posizione, Scacchiera& scacchiera) { 
  //Controllo che la casella di arrivo non sia quella di partenza
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;

  //Chiamata al metodo mossa_valida che controlla che la mossa passata sia valida 
  int mossa_valida = this->mossa_valida(posizione, scacchiera);
  //Se la mossa è valida aggiorno lo stato dell'oggetto, ovvero la sua posizione
  if(mossa_valida == true || mossa_valida == EN_PASSANT  || mossa_valida == ARROCCO) {
      posizione_ = posizione;
  }

  //Se la mossa non da scacco la restituisco alla funzione chiamante
  return mossa_valida;
}

//ovverride dell'operatore <<
std::ostream& operator<<(std::ostream& os, const Pezzo& temp) {
  //conversione del char contenuto in temp.figura_ a stringa
  os << std::string(1,temp.get_figura());
  return os;
}