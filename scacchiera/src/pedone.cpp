/*
  Nordio Gianluca 2007959
*/

#include "./../include/scacchiera.h"
#include "./../include/pedone.h"

Pedone::Pedone(Casella posizione, Colore colore) { 
  //inizializzate variabili membro ereditate da pezzo
  posizione_ = posizione;
  colore_ = colore;

  //inizializzata figura sulla base del colore del pezzo
  if(colore == Colore::nero)
    figura_ = 'P';
  else
    figura_ = 'p';
}

int Pedone::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){
  //indice colore indica se ci si muove in negativo o positivo a seconda del colore
  int indice_colore = 1;
  if(colore_ == Pezzo::Colore::nero)
    indice_colore = -1;

  //verifica che non ci sia una pedina dello stesso colore nella posizione_finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((scacchiera.get_casella(posizione_finale))->get_colore() == colore_)
      return false;

  //verifica che il movimento sia corretto
  if(posizione_finale.get_riga() == posizione_.get_riga() + indice_colore){ 
    // colonna uguale (non mangia pezzi)
    if((posizione_finale.get_colonna() == posizione_.get_colonna()) && (scacchiera.get_casella(posizione_finale) == nullptr)){ 
      return true;
    }

    //si sposta di una colonna e una riga e mangia
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(posizione_finale) != nullptr)){ 
      return true;
    }

    //mossa speciale en passant
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna())) != nullptr)){ 
      Pezzo *pezzo_affianco = scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna()));
      if(tolower(pezzo_affianco->get_figura()) == 'p') //se il pezzo accanto è un pedone
        if(pezzo_affianco->get_colore() != colore_) //il pezzo accanto è avversario
          if(static_cast<Pedone*>(pezzo_affianco)->mossa_salto_ == scacchiera.get_mosse_totali()) //enpassant valido
            return EN_PASSANT;  //la mossa fatta è l'enpassant 
    }
  }
  
  //caso in cui si sposta di due righe
  if((posizione_finale.get_riga() == posizione_.get_riga() + (indice_colore * 2)) && posizione_finale.get_colonna() == posizione_.get_colonna()) 
  {
    //controlla che sia la prima mossa bianca e che non ci siano pezzi nelle due caselle davanti al pedone
    if(colore_ == Pezzo::Colore::bianco) {
      if((posizione_.get_riga() == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga() + 1, posizione_.get_colonna())) == nullptr) && (scacchiera.get_casella(posizione_finale)) == nullptr){
        return SALTO_PEDONE; //la mossa è il salto del pedone di 2
        //se non si tratta della simulazione serve sapere che si tratta di una mossa
        //di due posizioni e che quindi va modificata la variabile mossa salto
      }
    }

    // controllo che sia la prima mossa nera e che non ci siano pezzi nelle due caselle davanti al pedone
    else if(colore_ == Pezzo::Colore::nero) {
      if((posizione_.get_riga() == 6) && (scacchiera.get_casella(Casella(posizione_.get_riga() - 1, posizione_.get_colonna())) == nullptr) && (scacchiera.get_casella(posizione_finale)) == nullptr){
        return SALTO_PEDONE;//la mossa è il salto del pedone di 2
        //se non si tratta della simulazione serve sapere che si tratta di una mossa
        //di due posizioni e che quindi va modificata la variabile mossa salto
      }
    }
  }
  return false;
}


//metodo che sposta il pezzo
int Pedone::mossa(Casella posizione, Scacchiera& scacchiera){ 
  //caso in cui non ci si sposta
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;

  int mossa_valida = this->mossa_valida(posizione, scacchiera);

  //si modifica la posizione se la mossa è valida
  if(mossa_valida == true || mossa_valida == EN_PASSANT) {
      posizione_ = posizione;
  }
  else if(mossa_valida == SALTO_PEDONE){  //caso del salto di due posizioni
    posizione_ = posizione;
    mossa_salto_ = scacchiera.get_mosse_totali() + 1; // serve per gestione en passant, salto del pedone e arrocco
  }

  //se non da scacco si passa il controllo di nuovo alla funzione chiamante
  return mossa_valida;
}
