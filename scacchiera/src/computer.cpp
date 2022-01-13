#include <iostream>

#include "./../include/computer.h"

Computer::Computer(Scacchiera* scacchiera, Pezzo::Colore colore){
  scacchiera_ = scacchiera;
  colore_ = colore;
  colore_avversario_ = colore_ == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
}

void Computer::gioca(){

  if(!scacchiera_->controllo_scacco(colore_)){
    if(scacchiera_->stallo(colore_)) //controlla che il giocatore non sia in stallo
      throw Eccezione("[Eccezione::Patta_Stallo]");
  }

  if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
    throw Eccezione("[Eccezione::Patta_Posizione]");

  //recupero il vettore contenente tutti i pezzi
  std::vector<Pezzo*> pezzi;
  if(colore_ == Pezzo::Colore::bianco)
    pezzi = scacchiera_->get_pezzi_bianchi();
  else
    pezzi = scacchiera_->get_pezzi_neri();

  int n_pezzo_scelto = rand() % pezzi.size();

  //controllo che il pezzo scelto possa muoversi
  bool eseguito = false;
  std::vector<Casella> mosse;
  while(!eseguito){
    mosse = scacchiera_->mosse_possibili(pezzi[n_pezzo_scelto]->get_posizione());
    if(mosse.size() == 0)
      n_pezzo_scelto = rand() % pezzi.size();
    else
      eseguito = true;
  }

  //recupero il vettore di mosse possibili e scelgo la casella in cui arrivare
  int mossa_scelta = rand() % mosse.size();

  eseguito = false;
  while(!eseguito){
    if(!scacchiera_->simulazione_mossa(pezzi[n_pezzo_scelto]->get_posizione(), mosse[mossa_scelta]))
      mossa_scelta = rand() % mosse.size();
    else
      eseguito = true;
  }

  scacchiera_->mossa(pezzi[n_pezzo_scelto]->get_posizione(), mosse[mossa_scelta]);
  
  if(scacchiera_->scaccomatto(colore_avversario_)){
    throw Eccezione("[Eccezione::Scaccomatto]");
  }

  if(scacchiera_->get_conta_mosse() >= 50)
    throw Eccezione("[Eccezione::Patta_Mosse]");

  scacchiera_->inserisci_scacchiera();
  if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
    throw Eccezione("[Eccezione::Patta_Posizione]");
      
  if(scacchiera_->pezzi_insufficienti()){
    throw Eccezione("[Eccezione::Patta_Materiale]");
  }
}


bool Computer::ricevuta_richiesta_patta(){
  int risposta = rand()%2;
  if(risposta)
    std::cout << "--> Richiesta accettata";
  else
    std::cout << "--> Richiesta rifiutata";
  return risposta;
}