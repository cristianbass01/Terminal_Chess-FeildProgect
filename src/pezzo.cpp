#include "./../include/pezzo.h"

bool Pezzo::mossa(Casella posizione, Scacchiera& scacchiera) { //metodo che sposta il pezzo
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;
  if(mossa_valida(posizione, scacchiera)) {
    posizione_ = posizione;
    return true;
  }
  return false;
}