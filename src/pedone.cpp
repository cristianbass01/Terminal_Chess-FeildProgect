#include "./../include/scacchiera.h"
#include "./../include/pedone.h"


Pedone::Pedone(Casella posizione, Colore colore) { 
  posizione_ = posizione;
  colore_ = colore;
  if(colore == Colore::nero)
    figura_ = 'P';
  else
    figura_ = 'p';
}

bool Pedone::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){
  int indice_colore = 1;
  if(colore_ == Pezzo::Colore::nero)
    indice_colore = -1;

  if(posizione_finale.get_riga() == posizione_.get_riga() + indice_colore){ // riga successiva
    if((posizione_finale.get_colonna() == posizione_.get_colonna()) && (scacchiera.get_casella(posizione_finale) == nullptr)) // colonna uguale (non mangia pezzi)
      return true;
    else if((abs(posizione_finale.get_colonna() - posizione_.get_colonna()) == 1) && (scacchiera.get_casella(posizione_finale) != nullptr)) // si sposta di una colonna e una riga e mangia
      return true;
  }
  /**else if(posizione_finale.get_riga() == posizione_.get_riga() + (indice_colore * 2)) // si sposta di due righe
  {
    if((colore_ == Pezzo::Colore::bianco) && (posizione_.get_riga() == 1))

  }
  **/
  return false;
}
