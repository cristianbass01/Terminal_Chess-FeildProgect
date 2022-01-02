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