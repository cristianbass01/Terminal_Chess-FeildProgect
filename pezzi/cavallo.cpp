#include "./../scacchiera.h"
#include "cavallo.h"

Cavallo::Cavallo(Casella posizione, Colore colore){
  colore_ = colore; 
  posizione_ = posizione;
  if(colore == Colore::nero)
    figura_ = 'C';
  else
    figura_ = 'c';
}

bool Cavallo::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){
  if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
    return false;
  
}