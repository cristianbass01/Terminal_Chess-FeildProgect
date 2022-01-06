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

int Re::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) {
  //calcolo di delta riga e delta colonna
  int delta_riga = posizione_finale.get_riga() - posizione_.get_riga();
  int delta_colonna = posizione_finale.get_colonna() - posizione_.get_colonna();

  //verifica che non ci sia una pedina dello stesso colore nella posizione finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;

  //gestisco arrocco
  if(arrocco_valido && delta_riga == 0 && abs(delta_colonna) == 2){
    //controllo se il re si sposta verso destra e se all'angolo destro c'è un pezzo
    if(delta_colonna == 2 && scacchiera.get_casella(Casella(posizione_.get_riga(), 7)) != nullptr){
      //controllo che il re non subisca scacco spostandosi di una posizione a destra
      if(this->simulazione_mossa(Casella(posizione_.get_riga(),5), scacchiera)){
        //controllo che il pezzo a destra sia una torre 
        if(tolower(scacchiera.get_casella(Casella(posizione_.get_riga(), 7))->get_figura()) == 't'){
        //salvo il pezzo torre con un alias
        Torre* torre_arrocco = static_cast<Torre*>(scacchiera.get_casella(Casella(posizione_.get_riga(), 7)));
        //se la torre ha l'arrocco valido e puo fare la mossa non mettendo in scacco il re
        if(torre_arrocco->get_arrocco_valido() && torre_arrocco->simulazione_mossa(Casella(posizione_.get_riga(), 5),scacchiera))
          return true;
        }
      }
    }
    if(delta_colonna == -2 && scacchiera.get_casella(Casella(posizione_.get_riga(), 0)) != nullptr){
      //controllo che il re non subisca scacco spostandosi di una posizione a destra
      if(this->simulazione_mossa(Casella(posizione_.get_riga(),3), scacchiera)){
        //controllo che il pezzo a destra sia una torre 
        if(tolower(scacchiera.get_casella(Casella(posizione_.get_riga(), 0))->get_figura()) == 't'){
        //salvo il pezzo torre con un alias
        Torre* torre_arrocco = static_cast<Torre*>(scacchiera.get_casella(Casella(posizione_.get_riga(), 0)));
        //se la torre ha l'arrocco valido e puo fare la mossa non mettendo in scacco il re
        if(torre_arrocco->get_arrocco_valido() && torre_arrocco->simulazione_mossa(Casella(posizione_.get_riga(), 5),scacchiera))
          return true;
        }
      }
    }
  }
  
  //verifico che il re si sposti in una delle caselle adiacenti
  if(abs(delta_riga) > 1 || abs(delta_colonna) > 1)
    return false;

  return true;
}