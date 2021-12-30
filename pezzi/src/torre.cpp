#include "./../../include/scacchiera.h"
#include "./../include/torre.h"

Torre::Torre(Casella posizione, Colore colore) {
  posizione_ = posizione;
  colore_ = colore;
  if(colore_ == Colore::nero)
    figura_ = 'T';
  else 
    figura_ = 't';
}

bool Torre::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) {
  return false;
}