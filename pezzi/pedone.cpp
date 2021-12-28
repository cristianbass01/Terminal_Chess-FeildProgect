#include "pedone.h"
Pedone::Pedone(Casella posizione, Colore colore) { 
  posizione_ = posizione;
  colore_ = colore;
  if(colore == Colore::nero)
    figura_ = 'P';
  else
    figura_ = 'p';
}

bool Pedone::mossa_valida(Casella posizione_finale, char** scacchiera){
  return false;
}
