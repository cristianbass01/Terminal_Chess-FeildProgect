#include "./../include/scacchiera.h"

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

  if(posizione_finale.get_riga() == posizione_.get_riga() + indice_colore){ // faccio un pass in avanti o laterale
    if((posizione_finale.get_colonna() == posizione_.get_colonna()) && (scacchiera.get_casella(posizione_finale) == nullptr)){ // colonna uguale (non mangia pezzi)
      return true;
    }
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(posizione_finale) != nullptr)){ // si sposta di una colonna e una riga e mangia
      return true;
    }
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna())) != nullptr)){ // mossa speciale en passant
      Pezzo *pezzo_affianco = scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna()));
      if(pezzo_affianco->get_figura() == 'p') //se il pezzo accanto è un pedone
        if(pezzo_affianco->get_colore() != colore_) //il pezzo accanto è avversario
          if(static_cast<Pedone*>(pezzo_affianco)->mossa_salto == scacchiera.get_conta_mosse()) //enpassant valido
            return EN_PASSANT;  //la mossa fatta è l'enpassant 
    }
  }
  
  if(posizione_finale.get_riga() == posizione_.get_riga() + (indice_colore * 2)) // si sposta di due righe
  {
    // controllo che sia la prima mossa bianca e che non ci siano pezzi nelle due caselle davanti al pedone
    if(colore_ == Pezzo::Colore::bianco) {
      if((posizione_.get_riga() == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga() + 1, posizione_.get_colonna())) == nullptr) && (scacchiera.get_casella(posizione_finale)) == nullptr){
        return SALTO_PEDONE; //la mossa è il salto del pedone di 2
        //se non si tratta della simulazione serve sapere che si tratta di una mossa
        //di due posizioni e che quindi va modificata la variabile mossa salto
    }
    
    // controllo che sia la prima mossa nera e che non ci siano pezzi nelle due caselle davanti al pedone
    if(colore_ == Pezzo::Colore::nero) 
      if((posizione_.get_riga() == 6) && (scacchiera.get_casella(Casella(posizione_.get_riga() - 1, posizione_.get_colonna())) == nullptr) && (scacchiera.get_casella(posizione_finale)) == nullptr){
        return SALTO_PEDONE;//la mossa è il salto del pedone di 2
        //se non si tratta della simulazione serve sapere che si tratta di una mossa
        //di due posizioni e che quindi va modificata la variabile mossa salto
    }
  }
  
  return false;
}

//metodo che sposta il pezzo
int Pedone::mossa(Casella posizione, Scacchiera& scacchiera) { 
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;
  
  Casella tmp = posizione_;

  int mossa_valida = this->mossa_valida(posizione, scacchiera);
  if(mossa_valida) {
      posizione_ = posizione;
  }
  else if(mossa_valida == EN_PASSANT  || mossa_valida == ARROCCO){
    // gestione en passant, salto del pedone e arrocco
    posizione_ = posizione;
  }
  
  //controllo scacco
  if(scacchiera.controllo_scacco(colore_)){
    posizione_ = tmp;
    return false;
  }

  //se non da scacco do il controllo di nuovo alla funzione chiamante
  return mossa_valida;
}

//metodo virtuale che controlla se la mossa è valida (ANCHE controllo scacco)
int Pedone::simulazione_mossa(Casella posizione, Scacchiera& scacchiera){
  Casella tmp = posizione_;

  int mossa = this->mossa(posizione, scacchiera);

  //se la mossa era valida e ha spostato i pezzi li faccio tornare alla posizione iniziale
  if(mossa || mossa == EN_PASSANT || mossa == ARROCCO){
    posizione_ = tmp;
    return true;
  }
  return false;
}