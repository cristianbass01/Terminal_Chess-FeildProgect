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

bool Cavallo::bloccato(Scacchiera& scacchiera){
  //simulo la mossa verso le 4 diagonali
  bool bordo_alto_vicino = this->posizione_.get_riga() + 1 > 7;
  bool bordo_alto_lontano = this->posizione_.get_riga() + 2 > 7;
  bool bordo_basso_vicino = this->posizione_.get_riga() - 1 < 0;
  bool bordo_basso_lontano = this->posizione_.get_riga() - 2 < 0;
  bool bordo_destro_vicino = this->posizione_.get_colonna() + 1 > 7;
  bool bordo_destro_lontano = this->posizione_.get_colonna() + 2 > 7;
  bool bordo_sinistro_vicino = this->posizione_.get_colonna() - 1 < 0;
  bool bordo_sinistro_lontano = this->posizione_.get_colonna() - 2 < 0;
  
  if(!bordo_alto_vicino && !bordo_destro_lontano)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + 1, this->posizione_.get_colonna() + 2)))
      return false;

  if(!bordo_alto_vicino && !bordo_sinistro_lontano)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + 1, this->posizione_.get_colonna() - 2)))
      return false;
  
  if(!bordo_basso_vicino && !bordo_destro_lontano)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() - 1, this->posizione_.get_colonna() + 2)))
      return false;
  
  if(!bordo_basso_vicino && !bordo_sinistro_lontano)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() - 1, this->posizione_.get_colonna() - 2)))
      return false;
  
  if(!bordo_alto_lontano && !bordo_destro_vicino)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + 2, this->posizione_.get_colonna() + 1)))
      return false;

  if(!bordo_alto_lontano && !bordo_sinistro_vicino)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + 2, this->posizione_.get_colonna() - 1)))
      return false;
  
  if(!bordo_basso_lontano && !bordo_destro_vicino)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() - 2, this->posizione_.get_colonna() + 1)))
      return false;
  
  if(!bordo_basso_lontano && !bordo_sinistro_vicino)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() - 2, this->posizione_.get_colonna() - 1)))
      return false;
  return true;
}