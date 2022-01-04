#include "./../include/scacchiera.h"
#include "./../include/re.h"

Re::Re(Casella posizione, Colore colore) { 
  //inizializzate variabili membro ereditate da pezzo
  posizione_ = posizione;
  colore_ = colore;
  arrocco_valido = true;

  //inizializzata figura sulla base del colore del pezzo
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
  //gestisco arrocco
  if(arrocco_valido && delta_riga == 0 && abs(delta_colonna) == 2){
    //verifico se la mossa passata è un arroco corto o lungo e se la torre coinvolta nella mossa ha già compiuto qualche spostamento
    if(delta_colonna == 2 && tolower((*(scacchiera.get_casella(Casella(posizione_.get_riga(), 7)))).get_figura()) == 't' && !(*static_cast<Torre*>(scacchiera.get_casella(Casella(posizione_.get_riga(), 7)))).get_arrocco_valido())
      return false;
    if(delta_colonna == -2 && tolower((*(scacchiera.get_casella(Casella(posizione_.get_riga(), 0)))).get_figura()) == 't' && !(*static_cast<Torre*>(scacchiera.get_casella(Casella(posizione_.get_riga(), 0)))).get_arrocco_valido())
      return false;
    //controllo se la torre può spostarsi, e quindi se gli spazi tra re e torre sono liberi, passando per il metodo mossa aggiorno anche il contatore delle mosse
    if(delta_colonna == 2 && scacchiera.mossa(Casella(posizione_.get_riga(), 7), Casella(posizione_.get_riga(), 5))){
      //sposto il re
      posizione_ = posizione_finale;
      throw Eccezione("[Eccezione::Arrocco_valido]");
    }
    if(delta_colonna == -2 && scacchiera.mossa(Casella(posizione_.get_riga(), 0), Casella(posizione_.get_riga(), 3))){
      //sposto il re
      posizione_ = posizione_finale;
      throw Eccezione("[Eccezione::Arrocco_valido]");
    }
    return true;
  }
  
  //verifico che il re si sposti in una delle caselle adiacenti
  if(abs(delta_riga) > 1 || abs(delta_colonna) > 1)
    return false;

  return true;
}