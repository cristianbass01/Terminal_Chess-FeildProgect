#include "alfiere.h"

Alfiere::Alfiere(Casella posizione, Colore colore) {
  colore_ = colore;
  posizione_ = posizione;
  if(colore == Colore::nero)
    figura_ = 'A';
  else
    figura_ = 'a';
}

void Alfiere::mossa(Casella posizione_finale){

}

bool Alfiere::mossa_valida(Casella posizione_finale){
  return false;
}