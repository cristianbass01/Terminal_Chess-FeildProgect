#include "./../include/scacchiera.h"
#include "./../include/re.h"

Re::Re(Casella posizione, Colore colore) { 
  posizione_ = posizione;
  colore_ = colore;
  if(colore_ == Colore::nero)
    figura_ = 'R';
  else
    figura_ = 'r';
}

bool Re::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) {
  //calcolo di delta riga e delta colonna
  int delta_riga = posizione_finale.get_riga() - posizione_.get_riga();
  int delta_colonna = posizione_finale.get_colonna() - posizione_.get_colonna();
  
  //verifica che non ci sia una pedina dello stesso colore nella posizione finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;
  
  //verifico che il re si sposti in una delle caselle adiacenti
  if(abs(delta_riga) > 1 || abs(delta_colonna) > 1)
    return false;

  return true;
}