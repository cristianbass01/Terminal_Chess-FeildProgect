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
  int delta_riga = posizione_.get_riga() - posizione_finale.get_riga();
  int delta_colonna = posizione_.get_colonna() - posizione_finale.get_colonna());
  if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
    return false;
  int temp_driga
  if(delta_riga > 0)
    temp_driga = delta_riga -1;
  else
    temp_driga = delta_riga +1;
  int temp_dcolonna;
  if(delta_riga > 0)
    temp_dcolonna = delta_colonna -1;
  else
    temp_dcolonna = delta_colonna +1;
  Casella temp_casella;
  while(temp_dcolonna != 0){
    temp_casella.set_colonna(posizione_.get_colonna() + temp_dcolonna);
    temp_casella.set_riga(posizione_.get_riga() + temp_driga);
    if((scacchiera.get_casella(temp_casella)) != nullptr )
      return false;
    if(temp_driga > 0)
      temp_driga--;
    else
      temp_driga++;
    if(temp_dcolonna > 0)
      temp_dcolonna--;
    else
      temp_dcolonna++;
  }
  if( delta_colonna < 0)
    delta_colonna *= -1; 
  if( delta_riga < 0)
    delta_riga *= -1; 
  if( delta_colonna != delta_riga)
    return false;
  return true;
}