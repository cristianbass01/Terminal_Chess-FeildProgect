#include "./../include/scacchiera.h"
#include "./../include/cavallo.h"

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
  int delta_riga = posizione_.get_riga() - posizione_finale.get_riga();
  int delta_colonna = posizione_.get_colonna() - posizione_finale.get_colonna());
  if( delta_colonna < 0)
    delta_colonna *= -1; 
  if( delta_riga < 0)
    delta_riga *= -1; 
  if(((delta_colonna == 2)&&(delta_riga == 1))||((delta_colonna == 1)&&(delta_riga == 2)))
    return true;
  return false;
}