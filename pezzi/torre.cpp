#include "torre.h"

Torre::Torre(Casella posizione, Colore colore) {
  posizione_ = posizione;
  colore_ = colore;
  if(colore_ == Colore::nero)
    figura_ = 'T';
  else 
    figura_ = 't';
}

bool mossa_valida(Casella posizione) {
  return false;
}