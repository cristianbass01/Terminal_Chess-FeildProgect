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

bool Pedone::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){
  int indice_colore = 1;
  if(colore_ == Pezzo::Colore::nero)
    indice_colore = -1;

  if(scacchiera.get_casella(posizione_finale) != nullptr){
    //verifica che non ci sia una pedina dello stesso colore nella posizione_finale
    if((scacchiera.get_casella(posizione_finale))->get_colore() == colore_)
      return false;
  }

  if(posizione_finale.get_riga() == posizione_.get_riga() + indice_colore){ // faccio un pass in avanti o laterale
    if((posizione_finale.get_colonna() == posizione_.get_colonna()) && (scacchiera.get_casella(posizione_finale) == nullptr)){ // colonna uguale (non mangia pezzi)
      en_passant_valid_ = false;
      return true;
    }
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(posizione_finale) != nullptr)){ // si sposta di una colonna e una riga e mangia
      en_passant_valid_ = false;
      return true;
    }
    if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna())) != nullptr)){ // mossa speciale en passant
      if(tolower(scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna()))->get_figura()) == 'p' && scacchiera.get_casella(Casella(posizione_.get_riga(), posizione_finale.get_colonna()))->get_colore() != colore_)
        throw Eccezione("[Eccezione::EnPassant]");
    }
  }
  
  if(posizione_finale.get_riga() == posizione_.get_riga() + (indice_colore * 2)) // si sposta di due righe
  {
    // controllo che sia la prima mossa bianca e che non ci siano pezzi nelle due caselle davanti al pedone
    if((colore_ == Pezzo::Colore::bianco) && (posizione_.get_riga() == 1) && (scacchiera.get_casella(Casella(posizione_.get_riga() + 1, posizione_.get_colonna())) == nullptr) && (scacchiera.get_casella(posizione_finale)) == nullptr){
      en_passant_valid_ = true;
      return true;
    }

    // controllo che sia la prima mossa nera e che non ci siano pezzi nelle due caselle davanti al pedone
    if((colore_ == Pezzo::Colore::nero) && (posizione_.get_riga() == 6) && (scacchiera.get_casella(Casella(posizione_.get_riga() - 1, posizione_.get_colonna())) == nullptr) && (scacchiera.get_casella(posizione_finale)) == nullptr){
      en_passant_valid_ = true;
      return true;
    }
  }
  
  return false;
}
