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

  if(posizione_finale.get_riga() == posizione_.get_riga() + indice_colore){ // faccio un pass in avanti o laterale
    if((posizione_finale.get_colonna() == posizione_.get_colonna()) && (scacchiera.get_casella(posizione_finale) == nullptr)){ // colonna uguale (non mangia pezzi)
      return true;
    }
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(posizione_finale) != nullptr)){ // si sposta di una colonna e una riga e mangia
      return true;
    }
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna())) != nullptr)){ // mossa speciale en passant
      Pezzo *pezzo_affianco = scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna()));
      if(tolower(pezzo_affianco->get_figura()) == 'p') //se il pezzo accanto è un pedone
        if(pezzo_affianco->get_colore() != colore_) //il pezzo accanto è avversario
          if(static_cast<Pedone*>(pezzo_affianco)->mossa_salto == scacchiera.get_mosse_totali()) //enpassant valido
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
  if((posizione.get_colonna() == posizione_.get_colonna() ) && (posizione.get_riga() == posizione_.get_riga()))
    return false;
  
  Casella tmp = posizione_;

  int mossa_valida = this->mossa_valida(posizione, scacchiera);

  if(mossa_valida == true || mossa_valida == EN_PASSANT) {
      posizione_ = posizione;
  }
  else if(mossa_valida == SALTO_PEDONE){
    // gestione en passant, salto del pedone e arrocco
    posizione_ = posizione;
    mossa_salto = scacchiera.get_mosse_totali() + 1;
  }

  //se non da scacco do il controllo di nuovo alla funzione chiamante
  return mossa_valida;
}

bool Pedone::bloccato(Scacchiera& scacchiera){
  //simulo le 4 mosse possibili in base al colore del pedone

  int versore_movimento;

  if(colore_ == Pezzo::Colore::bianco)
    versore_movimento = 1;
  else 
   versore_movimento = -1;
  
  bool riga_salto_bianco = this->posizione_.get_riga() == 1;
  bool riga_salto_nero = this->posizione_.get_riga() == 6;
  bool bordo_destro = this->posizione_.get_colonna() + 1 > 7;
  bool bordo_sinistro = this->posizione_.get_colonna() - 1 < 0;

  //simulo mossa in avanti senza catturare pezzi (se sono nell'ultima riga avrò gia fatto la promozione quindi il controllo è superfluo)
  if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + versore_movimento, this->posizione_.get_colonna() )))
    return false;

  //simulo salto iniziale di 2 caselle controllando di trovarmi nella riga giusta per poterlo fare
  if((riga_salto_bianco && colore_ == Pezzo::Colore::bianco) || (riga_salto_nero && colore_ == Pezzo::Colore::nero))
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + (2 * versore_movimento), this->posizione_.get_colonna() )))
      return false;

  //simulo lo spostamento laterale catturando un altro pezzo a destra
  if(!bordo_destro)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + versore_movimento, this->posizione_.get_colonna() + 1)))
      return false;
  
  if(!bordo_sinistro)
    if(scacchiera.simulazione_mossa(this->posizione_, Casella(this->posizione_.get_riga() + versore_movimento, this->posizione_.get_colonna() - 1)))
      return false;
      
  return true;
}