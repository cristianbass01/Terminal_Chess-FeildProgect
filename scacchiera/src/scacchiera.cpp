/*
  Bassotto Cristian 2000169
  Nordio Gianluca 2007959
  Cinel Giovanni 2000147
*/

#include "./../include/scacchiera.h"

Scacchiera::Scacchiera() {
  //inizializzazione tutti puntatori a nullptr
  for(int i = 0; i < RIGHE; i++) 
    for(int j = 0; j < COLONNE; j++) 
      scacchiera[i][j] = nullptr;


  //inizializzazione vari puntatori caselle bianche 
  scacchiera[0][0] = new Torre{Casella{0,0},Pezzo::Colore::bianco};
  scacchiera[0][7] = new Torre{Casella{0,7},Pezzo::Colore::bianco};

  scacchiera[0][1] = new Cavallo{Casella{0,1},Pezzo::Colore::bianco};
  scacchiera[0][6] = new Cavallo{Casella{0,6},Pezzo::Colore::bianco};

  scacchiera[0][2] = new Alfiere{Casella{0,2},Pezzo::Colore::bianco};
  scacchiera[0][5] = new Alfiere{Casella{0,5},Pezzo::Colore::bianco};

  scacchiera[0][3] = new Regina{Casella{0,3},Pezzo::Colore::bianco};
  scacchiera[0][4] = new Re{Casella{0,4},Pezzo::Colore::bianco};

  //inizializzazione variabile re_bianco_
  re_bianco_ = scacchiera[0][4];

  //inizializzazione di pedoni bianchi
  constexpr int RIGA_PEDONI_BIANCHI = 1;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_BIANCHI][i] = new Pedone{Casella{RIGA_PEDONI_BIANCHI, i}, Pezzo::Colore::bianco};
  }

  //inizializzazione vettore contenente i pezzi bianchi ancora vivi
  for(int i = 0; i < COLONNE; i++) {
    for(int j = 0; j < 2; j++)
      pezzi_bianchi_.push_back(scacchiera[j][i]);   
  }  

  //inizializzazione vari puntatori caselle nere
  scacchiera[7][0] = new Torre{Casella{7,0},Pezzo::Colore::nero};
  scacchiera[7][7] = new Torre{Casella{7,7},Pezzo::Colore::nero};

  scacchiera[7][1] = new Cavallo{Casella{7,1},Pezzo::Colore::nero};
  scacchiera[7][6] = new Cavallo{Casella{7,6},Pezzo::Colore::nero};

  scacchiera[7][2] = new Alfiere{Casella{7,2},Pezzo::Colore::nero};
  scacchiera[7][5] = new Alfiere{Casella{7,5},Pezzo::Colore::nero};

  scacchiera[7][3] = new Regina{Casella{7,3},Pezzo::Colore::nero};
  scacchiera[7][4] = new Re{Casella{7,4},Pezzo::Colore::nero};

  //inizializzazione variabile di scacchiera che contiene posizione del re nero
  re_nero_ = scacchiera[7][4];

  //inizializzazione pedoni neri
  constexpr int RIGA_PEDONI_NERI = 6;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_NERI][i] = new Pedone{Casella{RIGA_PEDONI_NERI, i}, Pezzo::Colore::nero};
  }

  //inizializzazione vettore contenente i pezzi neri ancora vivi
  for(int i = 0; i < COLONNE; i++) {
    for(int j = 7; j > 5; j--)
      pezzi_neri_.push_back(scacchiera[j][i]);   
  } 

  //inizializzo a 0 il contatore delle mosse
  conta_mosse_ = 0; 
  mosse_totali_ = 0;
}

Scacchiera::~Scacchiera() {
  //delete di tutti i puntatori agli oggetti non mangiati
  for(int i = 0; i < RIGHE; i++) {
    for(int j = 0; j < COLONNE; j++) {
      if(scacchiera[i][j] != nullptr)
        delete scacchiera[i][j];
    }
  }
}

std::string Scacchiera::log_mosse(){
  std::string mosse;
  //realizzazione del log della partita
  for(std::string s : log_mosse_) {
    mosse += s;
  }
  return mosse;
}

std::ostream& operator<<(std::ostream& os, const Scacchiera& scacchiera) {
  //stampato turno corrente
  os << "Turno: " << ( scacchiera.get_mosse_totali() / 2 ) + 1 << '\n';
  os << "Mosse totali: " <<  scacchiera.get_mosse_totali() << '\n' << '\n';
  /* 
  la stampa avviene in modo specchiato rispetto a com'è veramente fatta la matrice 
  ciò consente di poter utilizzare le righe e le colonne passate dal giocatore umano
  direttamente nella matrice modificandole di un offset
  */
  os<< "   ---------------------------------" << std::endl;
  for(int i = Scacchiera::RIGHE - 1; i >= 0; i--) {
    os<<i + 1<<' ';
    for(int j = 0; j < Scacchiera::COLONNE; j++) {
      if((scacchiera.get_casella(Casella{i,j}) == nullptr))
        os<<" |  ";
      else{
        os<<" | " << scacchiera.get_casella(Casella{i,j})->get_figura();
      }
    }
      os<<" |" << std::endl;
      os<< "   ---------------------------------" << std::endl;
  }
  os<<"   "<<"  A   B   C   D   E   F   G   H"<<std::endl; 
  return os;
}

void Scacchiera::stampa() const{
  //stampato turno corrente
  std::cout << "Turno: " << ( get_mosse_totali() / 2 ) + 1 << std::endl<<std::endl;
  std::cout << "Mosse totali: " <<  this->get_mosse_totali() << std::endl;
  /* 
  la stampa avviene in modo specchiato rispetto a com'è veramente fatta la matrice 
  ciò consente di poter utilizzare le righe e le colonne passate dal giocatore umano
  direttamente nella matrice modificandole di un offset
  */
  std::cout << "   ---------------------------------" << std::endl;
  for(int i = RIGHE - 1; i >= 0; i--) {
    std::cout<<i + 1<<' ';
    for(int j = 0; j < COLONNE; j++) {
      if(scacchiera[i][j] == nullptr)
        std::cout << " |  ";
      else{
        std::cout <<" | ";
        switch (scacchiera[i][j]->get_figura())
        {
        case 'P':
            std::cout<< "♙";
          break;
        case 'p':
            std::cout<< "♟";
          break;
        case 'R':
          std::cout<< "♔";
          break;
        case 'r':
          std::cout<< "♚";
          break;
        case 'D':
          std::cout<< "♕";
          break;
        case 'd':
          std::cout<< "♛";
          break;
        case 'A':
          std::cout<< "♗";
          break;
        case 'a':
          std::cout<< "♝";
          break;
        case 'T':
          std::cout<< "♖";
          break;
        case 't':
          std::cout<< "♜";
          break;
        case 'C':
          std::cout<< "♘";
          break;
        case 'c':
          std::cout<< "♞";
          break;
        default:
          break;
        } ;
      }
    }
      std::cout<<" |" << std::endl;
      std::cout << "   ---------------------------------" << std::endl;
  }
  std::cout<<"   "<<"  A   B   C   D   E   F   G   H"<<std::endl;          
}


Pezzo* Scacchiera::get_casella(Casella posizione) const{
  //ritorna puntatore a pezzo salvato nella casella passata
  return (scacchiera[posizione.get_riga()][posizione.get_colonna()]);
}

bool Scacchiera::controllo_scacco(Pezzo::Colore colore){
  //re_scelto è un puntatore che punta al re del colore avversario
  Pezzo* re_scelto;
  colore == Pezzo::Colore::bianco ?  re_scelto = re_bianco_ : re_scelto = re_nero_;  

  //verifica che nessun pezzo presente sulla scacchiera possa mangiare il re 
  if(colore == Pezzo::Colore::bianco)
  {
    for(int i = 0; i<pezzi_neri_.size(); i++)
      if(this->simulazione_mossa(pezzi_neri_[i]->get_posizione(),re_scelto->get_posizione()))
        return true;
        
  }
  else{
    for(int i = 0; i<pezzi_bianchi_.size(); i++)
      if(this->simulazione_mossa(pezzi_bianchi_[i]->get_posizione(),re_scelto->get_posizione()))
        return true;
  }
  return false;
}

bool Scacchiera::mossa(Casella posizione_in, Casella posizione_fin) {
  //caso in cui nella posizione iniziale si trova nullptr
  if(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] == nullptr)
    throw Eccezione{"--> [ERRORE] Nella casella selezionata non c'è nessun pezzo da muovere"};

  Pezzo* pezzo_mosso = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
  Pezzo* pezzo_mangiato = scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()];
  
  switch(pezzo_mosso->mossa(posizione_fin, *(this))) {
    case Pezzo::EN_PASSANT:{
      //viene effettuata la mossa
      pezzo_mangiato = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()];
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = nullptr;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;

      if(pezzo_mangiato != nullptr) {
        //il pezzo che è stato mangiato viene rimosso dal rispettivo vettore pezzi_***
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
          pezzi_bianchi_.erase(std::find(pezzi_bianchi_.begin(), pezzi_bianchi_.end(), pezzo_mangiato));
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
          pezzi_neri_.erase(std::find(pezzi_neri_.begin(), pezzi_neri_.end(), pezzo_mangiato));
      }

      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())) { 
        //vengono ristabilite le posizioni di partenza
        scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
        pezzo_mosso->set_posizione(posizione_in);
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
        std::cout<<"--> [ERRORE] Questa mossa mette il tuo re sotto scacco"<<std::endl;
        
        //controllo se il pezzo mangiato è un pezzo effettivo
        if(pezzo_mangiato != nullptr) {
          //il pezzo che è stato mangiato viene rimesso nel rispettivo vettore pezzi_***
          if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
            pezzi_bianchi_.push_back(pezzo_mangiato);
          if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
            pezzi_neri_.push_back(pezzo_mangiato);
        }
        return false;
      }
      break;
    }
    case Pezzo::ARROCCO:{
      //viene effettuata la mossa
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      int delta_colonna = posizione_fin.get_colonna() -posizione_in.get_colonna();
      if(delta_colonna == 2){
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1] = scacchiera[posizione_in.get_riga()][7];
        scacchiera[posizione_in.get_riga()][7] = nullptr;
      }
      else{
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1] = scacchiera[posizione_in.get_riga()][0];
        scacchiera[posizione_in.get_riga()][0] = nullptr;
      }

      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())){
        //vengono ristabilite le posizioni di partenza
        scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
        pezzo_mosso->set_posizione(posizione_in);
        //ristabilisco la posizione della torre
        if(delta_colonna == 2){
          scacchiera[posizione_in.get_riga()][7] = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1];
          scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1] = nullptr;
        }
        else{
          scacchiera[posizione_in.get_riga()][0] = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1];
          scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1] = nullptr;
        }
        std::cout<<"--> [ERRORE] Questa mossa mette il tuo re sotto scacco"<<std::endl;
        return false;
      }
      
      //aggiorno la posizione interna alla torre mossa
      if(delta_colonna == 2)
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1]->set_posizione(Casella{posizione_in.get_riga(), posizione_fin.get_colonna() - 1});
      else
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1]->set_posizione(Casella{posizione_in.get_riga(), posizione_fin.get_colonna() + 1});

      break;
    }
    case Pezzo::SALTO_PEDONE:{
      //modificata scacchiera
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      
      //caso in cui metto il mio re sotto scacco
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        //ripristinate le condizioni iniziali
        scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
        pezzo_mosso->set_posizione(posizione_in);
        (static_cast<Pedone*>(pezzo_mosso))->reset_mossa_salto();
        std::cout<<"--> [ERRORE] Questa mossa mette il tuo re sotto scacco"<<std::endl;
        return false;
      }
      break;
    }
    case true:{
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;

      if(pezzo_mangiato != nullptr) {
        //il pezzo che è stato mangiato viene rimosso dal rispettivo vettore pezzi_***
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
          pezzi_bianchi_.erase(std::find(pezzi_bianchi_.begin(), pezzi_bianchi_.end(), pezzo_mangiato));
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
          pezzi_neri_.erase(std::find(pezzi_neri_.begin(), pezzi_neri_.end(), pezzo_mangiato));
      }
      //caso in cui metto il mio re sotto scacco
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        //ripristinate le condizioni iniziali
        scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
        pezzo_mosso->set_posizione(posizione_in);
        std::cout<<"--> [ERRORE] Questa mossa mette il tuo re sotto scacco"<<std::endl;
        
        //controllo se il pezzo mangiato è un pezzo effettivo
        if(pezzo_mangiato != nullptr) {
          //il pezzo che è stato mangiato viene rimesso nel rispettivo vettore pezzi_***
          if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
            pezzi_bianchi_.push_back(pezzo_mangiato);
          if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
            pezzi_neri_.push_back(pezzo_mangiato);
        }
        return false;
      }
    
      break;
    }
    case false:{
      return false;
      break;
    }
  }

  //caso in cui c'è stato un pezzo mangiato
  if(pezzo_mangiato != nullptr) {
    delete pezzo_mangiato;

    // bisogna azzerare contatore mosse perchè viene mangiato un pezzo, 
    //lo si pone a -1 perchè successivamente verrà incrementato di 1 o posto a 0
    conta_mosse_ = -1;    
  }

  //se il pezzo mosso è un re si blocca la possibilità di fare l'arrocco
  if(tolower(pezzo_mosso->get_figura()) == 'r' || tolower(pezzo_mosso->get_figura()) == 't')
    static_cast<Torre*>(pezzo_mosso)->invalido_arrocco();
  
  //se si muove un pedone viene azzerato il contatore delle mosse
  if(tolower(pezzo_mosso->get_figura()) == 'p'){
    conta_mosse_ = 0;
  }
  else
    conta_mosse_++;

  //mossa valida fatta, aggiorno il contatore
  mosse_totali_++;

  //inserimento mossa nel log generando una stringa che indica la mossa
  std::string mossa_testuale;
  mossa_testuale.append(1, posizione_in.get_colonna()+'A');
  mossa_testuale.append(1, posizione_in.get_riga()+1+'0');
  mossa_testuale.append(1, ' ');
  mossa_testuale.append(1, posizione_fin.get_colonna()+'A');
  mossa_testuale.append(1, posizione_fin.get_riga()+1+'0');
  mossa_testuale.append(1, '\n');
  log_mosse_.push_back(mossa_testuale);
  
  return true;
}

bool Scacchiera::scaccomatto(Pezzo::Colore colore) {
  Pezzo* pezzo_attaccante = pezzo_scacco(colore);
  if(pezzo_attaccante != nullptr){
    //re_scelto è un puntatore che punta al re del colore dato
    Re* re_scelto;
    colore == Pezzo::Colore::bianco ?  re_scelto = static_cast<Re*>(re_bianco_) : re_scelto = static_cast<Re*>(re_nero_);  

    //controllo se il re può muoversi senza subire scacco
    if(re_scelto->bloccato(*this)){
      //creo un array con tutte le posizioni in cui poter bloccare il pezzo attaccante
      std::vector<Casella> posizioni = mosse_possibili(pezzo_attaccante->get_posizione());
      posizioni.push_back(pezzo_attaccante->get_posizione());
      //testo se posso mettermi in almeno una posizione in cui passa il pezzo attaccante 
      //o se posso mangiarlo senza subire ancora scacco
      for(unsigned int j = 0; j < posizioni.size(); j++){
        if(colore == Pezzo::Colore::bianco){
          for(int i = 0; i<pezzi_bianchi_.size(); i++)
            if(this->simulazione_mossa(pezzi_bianchi_[i]->get_posizione(),posizioni[j]))
              return false;
        }
        else{
          for(int i = 0; i<pezzi_neri_.size(); i++)
            if(this->simulazione_mossa(pezzi_neri_[i]->get_posizione(),posizioni[j]))
              return false;
        }
      }
      return true;
    }
    return false;
  }
  
  return false;
}

Pezzo* Scacchiera::pezzo_scacco(Pezzo::Colore colore){
  //re_scelto è un puntatore che punta al re del colore avversario
  Pezzo* re_scelto;
  colore == Pezzo::Colore::bianco ?  re_scelto = re_bianco_ : re_scelto = re_nero_;  

  //verifica che nessun pezzo presente sulla scacchiera possa mangiare il re 
  if(colore == Pezzo::Colore::bianco){
    for(int i = 0; i<pezzi_neri_.size(); i++)
      if(this->simulazione_mossa(pezzi_neri_[i]->get_posizione(),re_scelto->get_posizione()))
        return pezzi_neri_[i];
        
  }
  else{
    for(int i = 0; i<pezzi_bianchi_.size(); i++)
      if(this->simulazione_mossa(pezzi_bianchi_[i]->get_posizione(),re_scelto->get_posizione()))
        return pezzi_bianchi_[i];
  }
  return nullptr;
        
}

int Scacchiera::promuovi(Casella pos_pedone) { // OTTIMIZZATA
  //promozione bianchi
  Pezzo* pedone;
  if(scacchiera[pos_pedone.get_riga()][pos_pedone.get_colonna()] == nullptr)
    return -1;
  if(tolower(scacchiera[pos_pedone.get_riga()][pos_pedone.get_colonna()]->get_figura()) == 'p')
    pedone = scacchiera[pos_pedone.get_riga()][pos_pedone.get_colonna()];
  else
    return -1;

  if(pedone->get_posizione().get_riga() == 7) {
    int colonna_pedone = pedone->get_posizione().get_colonna();
    pezzi_bianchi_.erase(std::find(pezzi_bianchi_.begin(), pezzi_bianchi_.end(), pedone));
    delete pedone; //cancellata dalla memoria dinamica
    return colonna_pedone;
  }

  //promozione neri
  else
    if(pedone->get_posizione().get_riga() == 0) {
      int colonna_pedone = pedone->get_posizione().get_colonna();
      pezzi_neri_.erase(std::find(pezzi_neri_.begin(), pezzi_neri_.end(), pedone));
      delete pedone; //cancellata dalla memoria dinamica
      return colonna_pedone;
    }
  return -1;
}

void Scacchiera::fine_promozione(char figura_pezzo, Pezzo::Colore colore_pezzo,int colonna_promozione){
  
  int riga_promozione = colore_pezzo == Pezzo::Colore::bianco ? 7 : 0;

  // crea il nuovo pezzo da sostituire al pedone promosso
  switch (figura_pezzo)
  {
  case 'd':
      scacchiera[riga_promozione][colonna_promozione] = new Regina{Casella{riga_promozione,colonna_promozione}, colore_pezzo};
    break;
  case 't':
      scacchiera[riga_promozione][colonna_promozione] = new Torre{Casella{riga_promozione,colonna_promozione}, colore_pezzo};
    break;
  case 'a':
      scacchiera[riga_promozione][colonna_promozione] = new Alfiere{Casella{riga_promozione,colonna_promozione}, colore_pezzo};
    break;
  case 'c':
      scacchiera[riga_promozione][colonna_promozione] = new Cavallo{Casella{riga_promozione,colonna_promozione}, colore_pezzo};
    break;
  default:
      scacchiera[riga_promozione][colonna_promozione] = new Regina{Casella{riga_promozione,colonna_promozione}, colore_pezzo};
    break;
  }

  // inserisce il pezzo nel vettore dei pezzi
  if(colore_pezzo == Pezzo::Colore::bianco)
    pezzi_bianchi_.push_back(scacchiera[riga_promozione][colonna_promozione]);
  else
    pezzi_neri_.push_back(scacchiera[riga_promozione][colonna_promozione]);
  
  // salva la promozione nel log
  std::string mossa_testuale;
  mossa_testuale.append(1, colonna_promozione+'A');
  mossa_testuale.append(1, riga_promozione+1+'0');
  mossa_testuale.append(1, ' ');
  mossa_testuale.append(1, '=');
  mossa_testuale.append(1, figura_pezzo);
  mossa_testuale.append(1, '\n');
  log_mosse_.push_back(mossa_testuale);

}

std::vector<Casella> Scacchiera::mosse_possibili(Casella posizione_pezzo){ 
  std::vector<Casella> v;
  Pezzo* pezzo_mosso = scacchiera[posizione_pezzo.get_riga()][posizione_pezzo.get_colonna()];
  //controlla se c'è un pezzo nella casella data
  if(pezzo_mosso != nullptr){
    // controlla se può andare in qualsiasi casella della scacchiera
    for(int i = 0; i < RIGHE; i++) {
      for(int j = 0; j < COLONNE; j++) {
          // simula la mossa
          if(this->simulazione_mossa(pezzo_mosso->get_posizione(),Casella{i,j}))
            // se può eseguire la mossa allora la salva nel vettore
            v.push_back(Casella{i,j});
      }
    }
  }
  return v;
}

std::string Scacchiera::stringa_per_mappa() {
  std::string temp = "";
  for(int i = 0; i < RIGHE; i++) {
    for(int j = 0; j < COLONNE; j++) {
      Pezzo* pezzo_corrente = scacchiera[i][j];
      if(pezzo_corrente == nullptr)
        temp.push_back(' ');
      else {
        switch(pezzo_corrente->get_figura()) {
          case 'p': //caso di pedone bianco
            if(static_cast<Pedone*>(pezzo_corrente)->get_mossa_salto() == mosse_totali_ - 1)
              temp.push_back('f');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;
          
          case 'P': //caso di pedone nero
            if(static_cast<Pedone*>(pezzo_corrente)->get_mossa_salto() == mosse_totali_ - 1)
              temp.push_back('F');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;

          case 'r': //caso di re bianco
            if(static_cast<Re*>(pezzo_corrente)->get_arrocco_valido())
              temp.push_back('k');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;
          
          case 'R': //caso di re nero
            if(static_cast<Re*>(pezzo_corrente)->get_arrocco_valido())
              temp.push_back('K');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;
          
          case 't': //caso di torre bianca
            if(static_cast<Torre*>(pezzo_corrente)->get_arrocco_valido())
              temp.push_back('g');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;

          case 'T': //caso di torre nera
            if(static_cast<Torre*>(pezzo_corrente)->get_arrocco_valido())
              temp.push_back('G');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;
          
          default:  //tutti i casi che non sono quelli precedenti (donna, alfiere e cavallo)
            temp.push_back(pezzo_corrente->get_figura());
            break;
        }
      }
    }
  }
  return temp;
}

bool Scacchiera::stallo(Pezzo::Colore colore){
  // controlla tra i pezi di un colore se almeno uno si possa muovere senza subire scacco
  
  std::vector<Pezzo*> pezzi;
  if(colore == Pezzo::Colore::bianco)
  {
    for(int i = 0; i<pezzi_bianchi_.size();i++)
      pezzi.push_back(pezzi_bianchi_[i]);
  }
  else{
    for(int i = 0; i<pezzi_neri_.size();i++)
      pezzi.push_back(pezzi_neri_[i]);
  }

  for(int i = 0; i < pezzi.size(); i++)
    if(this->mosse_possibili(pezzi[i]->get_posizione()).size() != 0)
      return false;
  return true;
}

int Scacchiera::get_ripetizioni_scacchiera() {
  //va a prendere nella mappa la key della scacchiera attuale
  return mappa_posizioni_[this->stringa_per_mappa()];
}

void Scacchiera::inserisci_scacchiera(){
  // inserisce la scacchiera attuale nella mappa incrementando il numero se già presente 
  mappa_posizioni_[this->stringa_per_mappa()] = this->get_ripetizioni_scacchiera() + 1;
}

//per il pareggio per insufficienza di materiale avrò 
//- re + alfiere vs re
//- re vs re
//- re + alfiere o cavallo vs re con alfiere o cavallo
//- re + 1 cavallo vs re (o re con 1 cavallo)
  
bool Scacchiera::pezzi_insufficienti(){
  //controllo non restino solo i due re
  if(pezzi_bianchi_.size() == 1 && pezzi_neri_.size() == 1)
    return true;

  if((pezzi_bianchi_.size() == 2 && pezzi_neri_.size() == 1) || (pezzi_bianchi_.size() == 1 && pezzi_neri_.size() == 2)){
    //controllo non restino solo i due re e un alfiere bianco o un cavallo bianco
    if(pezzi_bianchi_.size() == 2){
      for(unsigned int i = 0; i < pezzi_bianchi_.size(); i++)
        if(pezzi_bianchi_[i]->get_figura() == 'a' || pezzi_bianchi_[i]->get_figura() == 'c')
          return true;
    }
    //controllo non restino solo i due re e un alfiere nero o un cavallo nero
    if(pezzi_neri_.size() == 2){
      for(unsigned int i = 0; i < pezzi_neri_.size(); i++)
        if(pezzi_neri_[i]->get_figura() == 'A' || pezzi_neri_[i]->get_figura() == 'C')
          return true;
    }
  }
  //controllo non restino solo  re + alfiere o cavallo vs re con alfiere o cavallo
  if(pezzi_bianchi_.size() == 2 && pezzi_neri_.size() == 2){
    bool alfiere_cavallo_bianco = false;
    bool alfiere_cavallo_nero = false;

    for(unsigned int i = 0; i < pezzi_bianchi_.size(); i++)
        if(pezzi_bianchi_[i]->get_figura() == 'a' || pezzi_bianchi_[i]->get_figura() == 'c')
          alfiere_cavallo_bianco = true;

    for(unsigned int i = 0; i < pezzi_neri_.size(); i++)
        if(pezzi_neri_[i]->get_figura() == 'A' || pezzi_neri_[i]->get_figura() == 'C')
          alfiere_cavallo_nero = true;

    if(alfiere_cavallo_bianco && alfiere_cavallo_nero)
      return true;
  }

  return false;
}

int Scacchiera::simulazione_mossa(Casella posizione_in, Casella posizione_fin) {

  //caso in cui nella posizione iniziale si trova nullptr
  if(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] == nullptr)
    throw Eccezione{"[Eccezione::NessunPezzo] Nella casella selezionata non c'è nessun pezzo da muovere"};

  int mossa = true;

  Pezzo* pezzo_mosso = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
  Pezzo* pezzo_mangiato = scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()];
  
  switch(pezzo_mosso->mossa(posizione_fin, *(this))) {
    case Pezzo::EN_PASSANT:{
      mossa = Pezzo::EN_PASSANT;
      //viene effettuata la mossa
      pezzo_mangiato = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()];
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = nullptr;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;

      if(pezzo_mangiato != nullptr) {
        //il pezzo che è stato mangiato viene rimosso dal rispettivo vettore pezzi_***
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
          pezzi_bianchi_.erase(std::find(pezzi_bianchi_.begin(), pezzi_bianchi_.end(), pezzo_mangiato));
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
          pezzi_neri_.erase(std::find(pezzi_neri_.begin(), pezzi_neri_.end(), pezzo_mangiato));
      }
      //controllo se con questa mossa metto sotto scacco l'avversario
      Pezzo::Colore colore_avversario = pezzo_mosso->get_colore() == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
      if(controllo_scacco(colore_avversario))
        mossa = Pezzo::SCACCO_AVVERSARIO;
      
      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        mossa = false;
      }

      //vengono ristabilite le posizioni di partenza
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
      pezzo_mosso->set_posizione(posizione_in);
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;

      //controllo se il pezzo mangiato è un pezzo effettivo
      if(pezzo_mangiato != nullptr) {
        //il pezzo che è stato mangiato viene rimesso nel rispettivo vettore pezzi_***
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
          pezzi_bianchi_.push_back(pezzo_mangiato);
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
          pezzi_neri_.push_back(pezzo_mangiato);
      }
      break;
    }
    case Pezzo::ARROCCO:{
      mossa = Pezzo::ARROCCO;
      //viene effettuata la mossa
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      int delta_colonna;
      delta_colonna = posizione_fin.get_colonna() -posizione_in.get_colonna();
      if(delta_colonna == 2){
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1] = scacchiera[posizione_in.get_riga()][7];
        scacchiera[posizione_in.get_riga()][7] = nullptr;
      }
      else{
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1] = scacchiera[posizione_in.get_riga()][0];
        scacchiera[posizione_in.get_riga()][0] = nullptr;
      }

      //aggiorno la posizione interna alla torre mossa
      if(delta_colonna == 2)
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1]->set_posizione(Casella{posizione_in.get_riga(), posizione_fin.get_colonna() - 1});
      else
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1]->set_posizione(Casella{posizione_in.get_riga(), posizione_fin.get_colonna() + 1});

      //controllo se con questa mossa metto sotto scacco l'avversario
      Pezzo::Colore colore_avversario = pezzo_mosso->get_colore() == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
      if(controllo_scacco(colore_avversario))
        mossa = Pezzo::SCACCO_AVVERSARIO;

      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())){
        mossa = false;
      }
      
      //vengono ristabilite le posizioni di partenza
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
      pezzo_mosso->set_posizione(posizione_in);
      //ristabilisco la posizione della torre nella scacchiera
      if(delta_colonna == 2){
        scacchiera[posizione_in.get_riga()][7] = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1];
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1] = nullptr;
      }
      else{
        scacchiera[posizione_in.get_riga()][0] = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1];
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1] = nullptr;
      }

      //ristabilisco la posizione interna alla torre mossa
      if(delta_colonna == 2)
        scacchiera[posizione_in.get_riga()][7]->set_posizione(Casella{posizione_in.get_riga(), 7});
      else
        scacchiera[posizione_in.get_riga()][0]->set_posizione(Casella{posizione_in.get_riga(), 0});

      break;
    }
    case Pezzo::SALTO_PEDONE:{
      //modificata scacchiera
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      
      //controllo se con questa mossa metto sotto scacco l'avversario
      Pezzo::Colore colore_avversario = pezzo_mosso->get_colore() == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
      if(controllo_scacco(colore_avversario))
        mossa = Pezzo::SCACCO_AVVERSARIO;

      //caso in cui metto il mio re sotto scacco
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        mossa = false;
      }
      
      //ripristinate le condizioni iniziali
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
      pezzo_mosso->set_posizione(posizione_in);
      (static_cast<Pedone*>(pezzo_mosso))->reset_mossa_salto();

      break;
    }
    case true:{
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;

      if(pezzo_mangiato != nullptr) {
        //il pezzo che è stato mangiato viene rimosso dal rispettivo vettore pezzi_***
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
          pezzi_bianchi_.erase(std::find(pezzi_bianchi_.begin(), pezzi_bianchi_.end(), pezzo_mangiato));
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
          pezzi_neri_.erase(std::find(pezzi_neri_.begin(), pezzi_neri_.end(), pezzo_mangiato));
      }

      //caso in cui metto il mio re sotto scacco
      if(pezzo_mangiato != nullptr && tolower(pezzo_mangiato->get_figura()) != 'r') {
        //controllo se con questa mossa metto sotto scacco l'avversario
        Pezzo::Colore colore_avversario = pezzo_mosso->get_colore() == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
        if(controllo_scacco(colore_avversario))
          mossa = Pezzo::SCACCO_AVVERSARIO;
        if(controllo_scacco(pezzo_mosso->get_colore()))
          mossa = false;
      }
      else if(pezzo_mangiato == nullptr){
        Pezzo::Colore colore_avversario = pezzo_mosso->get_colore() == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
        if(controllo_scacco(colore_avversario))
          mossa = Pezzo::SCACCO_AVVERSARIO;
        if(controllo_scacco(pezzo_mosso->get_colore()))
          mossa = false;
      }


      //ripristinate le condizioni iniziali
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
      pezzo_mosso->set_posizione(posizione_in);

      //controllo se il pezzo mangiato è un pezzo effettivo
      if(pezzo_mangiato != nullptr) {
        //il pezzo che è stato mangiato viene rimesso nel rispettivo vettore pezzi_***
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
          pezzi_bianchi_.push_back(pezzo_mangiato);
        if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
          pezzi_neri_.push_back(pezzo_mangiato);
      }
      break;
    }
    case false:{
      mossa = false;
      break;
    }
  }
  return mossa;
}