/*
  Nordio Gianluca 2007959
*/
#include <iostream>

#include "./../include/computer.h"

Computer::Computer(Scacchiera* scacchiera, Pezzo::Colore colore){
  //inizializzati membri della classe
  scacchiera_ = scacchiera;
  colore_ = colore;
  colore_avversario_ = (colore_ == Pezzo::Colore::bianco) ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
}

void Computer::gioca(){

  if(!scacchiera_->controllo_scacco(colore_)){
    if(scacchiera_->stallo(colore_)) //controlla che il giocatore non sia in stallo
      throw Eccezione("[Eccezione::Patta_Stallo]");
  }

  //verifica che la scacchiera non si sia già ripetuta 4 volte prima di questa
  if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
    throw Eccezione("[Eccezione::Patta_Posizione]");

  //recupera il vettore contenente tutti i pezzi
  std::vector<Pezzo*> pezzi;
  if(colore_ == Pezzo::Colore::bianco)
    pezzi = scacchiera_->get_pezzi_bianchi();
  else
    pezzi = scacchiera_->get_pezzi_neri();

  //selezione randomica di un pezzo
  int n_pezzo_scelto = rand() % pezzi.size();

  //controlla che il pezzo scelto possa muoversi
  bool eseguito = false;
  std::vector<Casella> mosse;
  while(!eseguito){
    mosse = scacchiera_->mosse_possibili(pezzi[n_pezzo_scelto]->get_posizione());
    if(mosse.size() == 0) //caso in cui il pezzo è bloccato
      n_pezzo_scelto = rand() % pezzi.size(); //viene scelto un altro pezzo
    else
      eseguito = true;
  }

  //recupera il vettore di mosse possibili e viene scelta la casella in cui arrivare
  int mossa_scelta = rand() % mosse.size();

  //viene effettuata la mossa
  scacchiera_->mossa(pezzi[n_pezzo_scelto]->get_posizione(), mosse[mossa_scelta]); 

  //gestione della promozione
  if(tolower(pezzi[n_pezzo_scelto]->get_figura()) == 'p'){
    int colonna_promozione = scacchiera_->promuovi(pezzi[n_pezzo_scelto]->get_posizione());
    if(colonna_promozione >= 0){
      char figura_pezzo = scelta_promozione();
      scacchiera_->fine_promozione(figura_pezzo, colore_, colonna_promozione);
    }
  }

  //casi particolari
  if(scacchiera_->scaccomatto(colore_avversario_)){ //scaccomatto
    throw Eccezione("[Eccezione::Scaccomatto]");
  }
  if(scacchiera_->get_conta_mosse() >= 50)  //numero mosse senza mangiare o muovere pedone
    throw Eccezione("[Eccezione::Patta_Mosse]");

  //caso ripezioni scacchiera
  scacchiera_->inserisci_scacchiera(); 
  if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
    throw Eccezione("[Eccezione::Patta_Posizione]");
  
  //caso pezzi insufficienti
  if(scacchiera_->pezzi_insufficienti()){
    throw Eccezione("[Eccezione::Patta_Materiale]");
  }
}

bool Computer::ricevuta_richiesta_patta(){
  //sceglie casualmente se accettare patta generando due valori
  int risposta = rand() % 2;
  if(risposta)
    std::cout << "--> Richiesta accettata";
  else
    std::cout << "--> Richiesta rifiutata";
  return risposta;
}

char Computer::scelta_promozione() {
  //costanti che indicano lettere
  constexpr char TORRE = 't';
  constexpr char REGINA = 'd';
  constexpr char ALFIERE = 'a';
  constexpr char CAVALLO = 'c';

  //scelta casuale del pezzo a cui fare la promozione
  int random = rand() % 4;
  switch(random) {
    case 0:
      return REGINA;
      break;
    
    case 1:
      return CAVALLO;
      break;
    
    case 2:
      return TORRE;
      break;
    
    case 3:
      return ALFIERE;
      break;
      
    default:
      return REGINA;
      break;
  }
}