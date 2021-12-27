#include "re.h"
Re::Re(Casella posizione, Pezzo::Colore colore) { 
  posizione_ = posizione;
  colore_ = colore;
  if(colore_ == Colore::nero)
    figura_ = 'R';
  else
    figura_ = 'r';
}

bool Re::mossa_valida(Casella posizione_finale) {
  return false;
}

void Re::mossa(Casella posizione_finale){

}