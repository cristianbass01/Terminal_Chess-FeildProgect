#include "cavallo.h"

Cavallo::Cavallo(Casella posizione, Colore colore){
  colore_ = colore; 
  posizione_ = posizione;
  if(colore == Colore::nero)
    figura_ = 'C';
  else
    figura_ = 'c';
}
void Cavallo::mossa(Casella posizione_finale){

}

bool Cavallo::mossa_valida(Casella posizione_finale){
  return false;
}