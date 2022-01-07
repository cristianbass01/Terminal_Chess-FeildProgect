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

  std::cout << "Giocatore Computer: ";

  //recupero il vettore contenente tutti i pezzi
  std::vector<Pezzo*> pezzi;
  if(colore_ == Pezzo::Colore::bianco)
    pezzi = scacchiera_->get_pezzi_bianchi();
  else
    pezzi = scacchiera_->get_pezzi_neri();

  int n_pezzo_scelto = rand() % pezzi.size();
  
  //controllo che il pezzo scelto possa muoversi
  bool done = false;
  while(!done){
    if(pezzi[n_pezzo_scelto]->bloccato(*scacchiera_))
      n_pezzo_scelto = rand() % pezzi.size();
    else
      done = true;
  }

  //recupero il vettore di mosse possibili e scelgo la casella in cui arrivare
  std::vector<Casella> mosse = scacchiera_->mosse_possibili(pezzi[n_pezzo_scelto]->get_posizione());
  int mossa_scelta = rand() % mosse.size();

  scacchiera_->mossa(pezzi[n_pezzo_scelto]->get_posizione(), mosse[mossa_scelta]);

  if(scacchiera_->scaccomatto(colore_avversario_)){
    throw Eccezione("[Eccezione::Scaccomatto]");
  }

  if(scacchiera_->get_conta_mosse() >= 50)
    throw Eccezione("[Eccezione::Patta_Mosse]");

  if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
    throw Eccezione("[Eccezione::Patta_Posizione]");
      
  if(scacchiera_->pezzi_insufficienti()){
    throw Eccezione("[Eccezione::Patta_Insufficenza_di_Pezzi]");
  }
}


bool Computer::ricevuta_richiesta_patta(){
  return rand()%2;
}