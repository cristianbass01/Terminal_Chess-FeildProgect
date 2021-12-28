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
  //parte per i biachi
  if(colore_ == Colore::bianco) {
    //caso in cui arretra
    if(posizione_.get_riga() >= posizione_finale.get_riga())
      return false;

    //caso in cui si trova nella posizione iniziale
    if((posizione_finale.get_riga() - posizione_.get_riga()) != 1) {
      if(posizione_.get_riga() != 1)
        return false;
      if((posizione_finale.get_riga() - posizione_.get_riga()) != 2)
        return false;
    }

    

    //caso in cui abbia un pezzo davanti

  }
  
  
  
  
}
