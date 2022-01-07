#include "./../include/scacchiera.h"
#include "./../include/torre.h"

Torre::Torre(Casella posizione, Colore colore) {
  //inizializzate variabili membro ereditate da pezzo
  posizione_ = posizione;
  colore_ = colore;
  arrocco_valido = true;
  
  //inizializzata figura sulla base del colore del pezzo
  if(colore_ == Colore::nero)
    figura_ = 'T';
  else 
    figura_ = 't';
}

int Torre::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) {
  //calcolo di delta riga e delta colonna
  int delta_riga = posizione_finale.get_riga() - posizione_.get_riga();
  int delta_colonna = posizione_finale.get_colonna() - posizione_.get_colonna();
  
  //verifica che non ci sia una pedina dello stesso colore nella posizione finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;

  //verifico che il movimento ia lungo una riga o lungo una colonna
  if(delta_colonna != 0 && delta_riga != 0)
    return false;
  
  //variabile che indica il verso
  int verso;

  //verifico non ci siano pedine nel cammino della torre se si muove lungo la riga
  if(delta_colonna == 0){
    if(delta_riga > 0)
      verso = 1;
    else
      verso = -1;
    for(int i = verso; abs(i) < abs(delta_riga) ; i += verso){
      if(scacchiera.get_casella(Casella(posizione_.get_riga() + i, posizione_.get_colonna())) != nullptr )
        return false;
    }
  }

  //verifico non ci siano pedine nel cammino della torre se si muove lungo la colonna
  if(delta_riga == 0){
    if(delta_colonna > 0)
      verso = 1;
    else
      verso = -1;
    for(int i = verso; abs(i) < abs(delta_colonna) ; i += verso){
      if(scacchiera.get_casella(Casella(posizione_.get_riga() , posizione_.get_colonna() + i)) != nullptr )
        return false;
    }
  }

  return true;
}

bool Torre::bloccato(Scacchiera& scacchiera){
  //simulo le mosse verso le 4 direzioni possibili 
  bool bordo_alto = this->posizione_.get_riga() + 1 > 7;
  bool bordo_basso = this->posizione_.get_riga() - 1 < 0;
  bool bordo_destro = this->posizione_.get_colonna() + 1 > 7;
  bool bordo_sinistro = this->posizione_.get_colonna() - 1 < 0;
  
  if(!bordo_alto)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + 1, this->posizione_.get_colonna())))
      return false;

  if(!bordo_sinistro)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga(), this->posizione_.get_colonna() - 1)))
      return false;
  
  if(!bordo_destro)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga(), this->posizione_.get_colonna() + 1)))
      return false;
  
  if(!bordo_basso)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() - 1, this->posizione_.get_colonna())))
      return false;
      
  return true;
}