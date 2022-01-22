/*
  Bassotto Cristian 2000169
*/

#include "./../include/scacchiera.h"
#include "./../include/re.h"

Re::Re(Casella posizione, Colore colore) { 
  //inizializzate variabili membro ereditate da pezzo
  posizione_ = posizione;
  colore_ = colore;
  arrocco_valido_ = true;

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
    if(scacchiera.get_casella(posizione_finale)->get_colore() == colore_)
      return false;

  //gestisco arrocco
  if(arrocco_valido_ && delta_riga == 0 && abs(delta_colonna) == 2){
    //controllo se il re si sposta verso destra e se all'angolo destro c'è un pezzo
    if(delta_colonna == 2 && scacchiera.get_casella(Casella{posizione_.get_riga(), 7}) != nullptr){
      //controllo che il re non subisca scacco spostandosi di una posizione a destra
      if(scacchiera.get_casella(Casella{posizione_.get_riga(),5}) == nullptr && scacchiera.simulazione_mossa(this->get_posizione(), Casella{posizione_.get_riga(),5})){
        //controllo che il pezzo a destra sia una torre 
        if(tolower(scacchiera.get_casella(Casella{posizione_.get_riga(), 7})->get_figura()) == 't'){
          //salvo il pezzo torre con un alias
          Torre* torre_arrocco = static_cast<Torre*>(scacchiera.get_casella(Casella{posizione_.get_riga(), 7}));
          //se la torre ha l'arrocco valido e puo fare la mossa non mettendo in scacco il re
          if(torre_arrocco->get_arrocco_valido() && scacchiera.simulazione_mossa(torre_arrocco->get_posizione(),Casella{posizione_.get_riga(), 5}))
            return ARROCCO;
        }
      }
    }
    else if(delta_colonna == -2 && scacchiera.get_casella(Casella{posizione_.get_riga(), 0}) != nullptr){
      //controllo che il re non subisca scacco spostandosi di una posizione a sinistra
      if(scacchiera.get_casella(Casella{posizione_.get_riga(),3}) == nullptr && scacchiera.simulazione_mossa(this->get_posizione(), Casella{posizione_.get_riga(),3})){
        //controllo che il pezzo a sinistra sia una torre 
        if(tolower(scacchiera.get_casella(Casella{posizione_.get_riga(), 0})->get_figura()) == 't'){
          //salvo il pezzo torre con un alias
          Torre* torre_arrocco = static_cast<Torre*>(scacchiera.get_casella(Casella(posizione_.get_riga(), 0)));
          //se la torre ha l'arrocco valido e puo fare la mossa non mettendo in scacco il re
          if(torre_arrocco->get_arrocco_valido() && scacchiera.simulazione_mossa(torre_arrocco->get_posizione(),Casella{posizione_.get_riga(), 3}))
            return ARROCCO;
        }
      }
    }
  }
  
  //verifico che il re si sposti in una delle caselle adiacenti
  if(abs(delta_riga) > 1 || abs(delta_colonna) > 1)
    return false;

  return true;
}


bool Re::bloccato(Scacchiera& scacchiera){
  //simulo le mosse possibili

  //variabile che salva true se il re si trova sul bordo alto della scacchiera, false altrimenti
  bool bordo_alto = this->posizione_.get_riga() + 1 > 7;

  //variabile che salva true se il re si trova sul bordo basso della scacchiera, false altrimenti
  bool bordo_basso = this->posizione_.get_riga() - 1 < 0;

  //variabile che salva true se il re si trova sul bordo destro della scacchiera, false altrimenti
  bool bordo_destro = this->posizione_.get_colonna() + 1 > 7;

  //variabile che salva true se il re si trova sul bordo sinistro della scacchiera, false altrimenti
  bool bordo_sinistro = this->posizione_.get_colonna() - 1 < 0;
  
  // controllo che il re non si trovi sul'angolo destro della scacchiera
  if(!bordo_alto && !bordo_destro)
    // simulo lo spostamento del re verso l'angolo alto dentro
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga() + 1, this->posizione_.get_colonna() + 1}))
      return false;

  // controllo che il re non si trovi sull'angolo alto sinistro della scacchiera
  if(!bordo_alto && !bordo_sinistro)
    // simulo la mossa del re verso l'angolo alto sinistro
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga() + 1, this->posizione_.get_colonna() - 1}))
      return false;
  
  // controllo che il re non si trovi sull'angolo basso destro della scacchiera
  if(!bordo_basso && !bordo_destro)
    // simulo la mossa del re verso l'angolo basso destro
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga() - 1, this->posizione_.get_colonna() + 1}))
      return false;
  
  // controllo che il re non si trovi sull'angolo basso sinistro della scacchiera
  if(!bordo_basso && !bordo_sinistro)
    // simulo la mossa del re verso l'angolo basso sinistro
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga() - 1, this->posizione_.get_colonna() - 1}))
      return false;

  // controllo che il re non si trovi lungo il bordo basso della scacchiera
  if (!bordo_alto)
    // simulo la mossa del re verso l'alto
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga() + 1, this->posizione_.get_colonna()}))
      return false;

  // controllo che il re non si trovi lungo il bordo basso della scacchiera
  if (!bordo_basso)
    // simulo la mossa del re verso il basso
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga() - 1, this->posizione_.get_colonna()}))
      return false;

  // controllo che il re non si trovi lungo il bordo destro della scacchiera
  if (!bordo_destro)
    // simulo la mossa del re verso destra
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga(), this->posizione_.get_colonna() + 1}))
      return false;

  // controllo che il re non si trovi lungo il bordo sinistro della scacchiera
  if (!bordo_sinistro)
    // simulo la mossa del re verso sinistra
    if(scacchiera.simulazione_mossa(this->posizione_, Casella{this->posizione_.get_riga(), this->posizione_.get_colonna() - 1}))
      return false;

  // Non controllo l'arrocco perchè se il re non si può spostare a sinistra o destra, non potrà nemmeno compiere l'arrocco
  return true;
}