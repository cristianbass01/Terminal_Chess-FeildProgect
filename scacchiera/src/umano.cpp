/*
  Bassotto Cristian 2000169
*/
#include <iostream>

#include "./../include/umano.h"

Umano::Umano(Scacchiera* scacchiera, Pezzo::Colore colore){
  scacchiera_ = scacchiera;
  colore_ = colore;
  colore_avversario_ = colore_ == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
}

void Umano::gioca(){

  std::cout << std::endl;
  if(scacchiera_->controllo_scacco(colore_)){
    std::cout<<"--> Attenzione! Sei sotto scacco!"<<std::endl;
  }
  else if(scacchiera_->stallo(colore_)) //controlla che il giocatore non sia in stallo
    throw Eccezione("[Eccezione::Patta_Stallo]");
  
  if(scacchiera_->get_ripetizioni_scacchiera() >= 3){
    if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
      throw Eccezione("[Eccezione::Patta_Posizione]");
    if(richiesta_patta())
      throw Eccezione("[Eccezione::Patta_Posizione]");
  }

  bool done = false; //mossa eseguita correttamente

  static constexpr int a = 97; // per trasformare da lettera a numero di colonna

  while(!done){
    std::cout << "Giocatore ";
    colore_ == Pezzo::Colore::bianco ? std::cout << "bianco (minuscole) " : std::cout << "nero (maiuscole) ";
    std::cout << "(per aiuto HE LP ):" << std::endl;

    //input della mossa
    std::string mossa;
    getline(std::cin, mossa);

    if((mossa.size() != 5 && mossa.size() != 8) || mossa[2] != ' ' || (mossa.size() == 8 && mossa[5] != ' '))
        std::cout << "--> Combinazione errata, riprova" << "\n";
    else{
      //tutte lettere in formato minuscolo
      for(int i = 0; i<mossa.size(); i++)
        mossa[i] = tolower(mossa[i]);

      if(mossa.compare("he lp") == 0) // Il giocatore vuole vedere le combinazioni disponibili
        combinazioni();
      else if(mossa.compare("ff ff") == 0) // Il giocatore vuole terminare la partita
        throw Eccezione("[Eccezione::Abbandono]");
      else if(mossa.compare("xx xx") == 0) // Il giocatore vuole vedere la scacchiera
        std::cout<< *scacchiera_; //OVERWRITING OPERATORE <<
      else{
        try
        {
          //creazione colonna iniziale
          int colonna_iniziale = mossa[0] - a; // in questo modo parto da a = 0 come colonna
          int riga_iniziale = mossa[1] - 49;
          Casella iniziale(riga_iniziale, colonna_iniziale);
          if(mossa[3] == 'm' && mossa[4] == 'm')
            mosse_lecite(iniziale);
          else{
            //creazione colonna finale
            int colonna_finale = mossa[3] - a; // in questo modo parto da a = 0 come colonna
            int riga_finale = mossa[4] - 49;
            Casella finale(riga_finale, colonna_finale);

            if(scacchiera_->get_casella(iniziale) != nullptr){
              if(scacchiera_->get_casella(iniziale)->get_colore() == colore_){
                done = scacchiera_->mossa(iniziale, finale);
                if(!done)
                  std::cout << "--> Mossa non valida" << std::endl;
                else{
                  std::cout << "--> Mossa eseguita" << std::endl;
                  int colonna_promozione = scacchiera_->promuovi(finale);
                  if(colonna_promozione >= 0){
                    char figura_pezzo = scelta_promozione();
                    scacchiera_->fine_promozione(figura_pezzo, colore_, colonna_promozione);
                  }
                  if(mossa.size() == 8){
                    if(mossa[6] == 'p' && mossa[7] == 'p'){
                      if(scacchiera_->get_ripetizioni_scacchiera() >= 3)
                        throw Eccezione("[Eccezione::Patta_Posizione]");
                      std::cout << "--> Richiesta di patta inviata all'altro giocatore" << std::endl;
                      throw Eccezione("[Eccezione::Richiesta_Patta]");
                    }
                    else{
                      std::cout << "--> Richiesta di patta non inviata per combinazione errata" << std::endl;
                      char risposta;
                      do{
                        std::cout << "--> Vuoi richiedere la patta? Y/n" << std::endl;
                        std::string riga_risposta;
                        getline(std::cin, riga_risposta);
                        risposta = tolower(riga_risposta[0]);
                        risposta = tolower(risposta);
                        if(risposta == 'y')
                          throw Eccezione("[Eccezione::Richiesta_Patta]");
                      }
                      while(risposta != 'n');
                    }
                  }
                }
              }
              else
                throw Eccezione("--> [ERRORE] Il pezzo che vuoi muovere è di un colore diverso dal tuo");
            }
            else
              throw Eccezione("--> [ERRORE] Nella casella selezionata non c'è nessun pezzo da muovere");
          }
        }
        catch(Eccezione e) // casella errata, mossa non valida o richiesta di patta all'altro giocatore
        {
          if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0)
            throw;
          std::cout<< e.errore() << '\n';
        }
      }
    }
    std::cout << std::endl;
  }
  if(scacchiera_->scaccomatto(colore_avversario_)){
    throw Eccezione("[Eccezione::Scaccomatto]");
  }

  if(scacchiera_->get_conta_mosse() >= 50)
    throw Eccezione("[Eccezione::Patta_Mosse]");

  scacchiera_->inserisci_scacchiera();
  if(scacchiera_->get_ripetizioni_scacchiera() >= 3){
    if(scacchiera_->get_ripetizioni_scacchiera() >= 5)
      throw Eccezione("[Eccezione::Patta_Posizione]");
    if(richiesta_patta())
      throw Eccezione("[Eccezione::Patta_Posizione]");
  }

  if(scacchiera_->pezzi_insufficienti()){
    throw Eccezione("[Eccezione::Patta_Materiale]");
  }
}

void Umano::combinazioni(){
  std::cout << std::endl;
  std::cout << "***************************************************************" << std::endl;
  std::cout << "*   Le possibili combinazioni di lettere per le mosse sono:   *" << std::endl;
  std::cout << "*   - A1 B2 : per spostare una pedina da A1 a B2              *" << std::endl;
  std::cout << "*   - A1 B2 PP: per spostare una pedina da A1 a B2            *" << std::endl;
  std::cout << "*               e chiedere patta all'altro giocatore          *" << std::endl;
  std::cout << "*   - A1 MM : per visualizzare le mosse disponibili per A1    *" << std::endl;
  std::cout << "*   - XX XX : per visualizzare la scacchiera completa         *" << std::endl;
  std::cout << "*   - HE LP : per visualizzare i comandi                      *" << std::endl;
  std::cout << "*   - FF FF : per lasciare il gioco                           *" << std::endl;
  std::cout << "*                                                             *" << std::endl;
  std::cout << "*   Il formato delle lettere non influisce (a = A)            *" << std::endl;
  std::cout << "***************************************************************" << std::endl;
  std::cout << std::endl;
}

bool Umano::ricevuta_richiesta_patta(){
  char risposta;
  do{
    std::cout << std::endl;
    std::cout << "Giocatore ";
    colore_ == Pezzo::Colore::bianco ? std::cout << "bianco (minuscole) " : std::cout << "nero (maiuscole) ";
    std::cout << std::endl;
    std::cout << "--> Il giocatore avversario ha chiesto di fare patta, acconsenti? Y/n" << std::endl;
    std::string riga_risposta;
    getline(std::cin, riga_risposta);
    risposta = tolower(riga_risposta[0]);
    if(risposta == 'y')
      return true;
  }
  while(risposta != 'n');
  return false;
}

bool Umano::richiesta_patta(){
  char risposta;
  do{
    std::cout << "Giocatore ";
    colore_ == Pezzo::Colore::bianco ? std::cout << "bianco (minuscole) " : std::cout << "nero (maiuscole) ";
    std::cout << std::endl;
    std::cout << "--> Posizione ripetuta per più di 3 volte, vuoi concludere la partita con una patta? Y/n" << std::endl;
    std::string riga_risposta;
    getline(std::cin, riga_risposta);
    risposta = tolower(riga_risposta[0]);
    if(risposta == 'y')
      return true;
  }
  while(risposta != 'n');
  return false;
}

char Umano::scelta_promozione(){
  char risposta;
  risposta = 'd';  //posta di default a donna
  do{
    std::cout << "Giocatore ";
    colore_ == Pezzo::Colore::bianco ? std::cout << "bianco (minuscole) " : std::cout << "nero (maiuscole) ";
    std::cout << std::endl;
    std::cout << "--> A che pezzo vuoi promuovere il pedone?" << std::endl;
    std::string riga_risposta;
    getline(std::cin, riga_risposta);
    risposta = tolower(riga_risposta[0]);
  }
  while(!(risposta == 't' || risposta == 'a' || risposta == 'c' || risposta == 'd'));
  return risposta;
}

void Umano::mosse_lecite(Casella pos_pezzo){
  if(scacchiera_->get_casella(pos_pezzo) == nullptr){
    std::cout << "--> Nessun pezzo nella casella scelta" << std::endl;
  }
  else{
    if(scacchiera_->get_casella(pos_pezzo)->get_colore() != colore_){
      std::cout << "--> Pezzo del colore avversario" << std::endl;
    }
    else{
      std::vector<Casella> mosse = scacchiera_->mosse_possibili(pos_pezzo);
      std::cout << "***************************************************************" << std::endl;
      if(mosse.size() == 0)
        std::cout << "*       Nessuna mossa possibile                               *" << std::endl;
      else
        std::cout << "*       Mosse lecite possibili:                               *" << std::endl;

      for(Casella pos_mossa : mosse){
        std::string mossa_testuale;
        mossa_testuale.append(1, pos_pezzo.get_colonna()+'A');
        mossa_testuale.append(1, pos_pezzo.get_riga()+1+'0');
        mossa_testuale.append(1, ' ');
        mossa_testuale.append(1, pos_mossa.get_colonna()+'A');
        mossa_testuale.append(1, pos_mossa.get_riga()+1+'0');
        int simula_mossa = scacchiera_->simulazione_mossa(pos_pezzo, pos_mossa);
        if(simula_mossa == Pezzo::SCACCO_AVVERSARIO){
          std::cout << "*       " << mossa_testuale << " --> Mette sotto scacco il re avversario         *" << std::endl;
          if(scacchiera_->get_casella(pos_mossa) != nullptr)
            std::cout << "*                e catturi un pezzo avversario                               *" << std::endl;
        }
        else if(simula_mossa == Pezzo::ARROCCO)
          std::cout << "*       " << mossa_testuale << " --> Arrocco                                     *" << std::endl;
        else if(simula_mossa == Pezzo::EN_PASSANT)
          std::cout << "*       " << mossa_testuale << " --> En Passant                                  *" << std::endl;
        
        if(scacchiera_->get_casella(pos_mossa) != nullptr)
          std::cout << "*       " << mossa_testuale << " --> Catturi un pezzo avversario                 *" << std::endl;
        else  
          std::cout << "*       " << mossa_testuale << "                                                 *" << std::endl;
      }
      std::cout << "***************************************************************" << std::endl;
    }
  }
}