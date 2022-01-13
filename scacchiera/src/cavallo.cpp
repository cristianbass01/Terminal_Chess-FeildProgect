/*
  Cinel Giovanni 2000147
*/

#include "./../include/scacchiera.h"
#include "./../include/cavallo.h"

Cavallo::Cavallo(Casella posizione, Colore colore){
  //inizializzate variabili membro ereditate da pezzo
  colore_ = colore; 
  posizione_ = posizione;

  //inizializzata figura sulla base del colore del pezzo
  if(colore == Colore::nero)
    figura_ = 'C';
  else
    figura_ = 'c';
}

int Cavallo::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){
  if(scacchiera.get_casella(posizione_finale) != nullptr){
    //verifica che non ci sia una pedina dello stesso colore nella posizione_finale
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;
  }
  //calcolo di delta riga e delta colonna
  int delta_riga = posizione_.get_riga() - posizione_finale.get_riga();
  int delta_colonna = posizione_.get_colonna() - posizione_finale.get_colonna();

  //modulo di delta riga e delta colonna
  if( delta_colonna < 0)
    delta_colonna *= -1; 
  if( delta_riga < 0)
    delta_riga *= -1;
  //verifica del movimento a L controllando che si sposti di 2 e 1
  if(((delta_colonna == 2)&&(delta_riga == 1)) || ((delta_colonna == 1)&&(delta_riga == 2)))
    return true;
  return false;
}