#include "./../include/scacchiera.h"
#include "./../include/alfiere.h"

Alfiere::Alfiere(Casella posizione, Colore colore) {
  colore_ = colore;
  posizione_ = posizione;
  if(colore == Colore::nero)
    figura_ = 'A';
  else
    figura_ = 'a';
}

bool Alfiere::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){
  return false;
}