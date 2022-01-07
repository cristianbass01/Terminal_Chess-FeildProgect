#include "./../include/scacchiera.h"

Scacchiera::Scacchiera() {

  //inizializzazione tutti puntatori a nullptr
  for(int i = 0; i < RIGHE; i++) 
    for(int j = 0; j < COLONNE; j++) 
      scacchiera[i][j] = nullptr;


  //inizializzazione vari puntatori caselle bianche 
  scacchiera[0][0] = new Torre(Casella(0,0),Pezzo::Colore::bianco);
  scacchiera[0][7] = new Torre(Casella(0,7),Pezzo::Colore::bianco);

  scacchiera[0][1] = new Cavallo(Casella(0,1),Pezzo::Colore::bianco);
  scacchiera[0][6] = new Cavallo(Casella(0,6),Pezzo::Colore::bianco);

  scacchiera[0][2] = new Alfiere(Casella(0,2),Pezzo::Colore::bianco);
  scacchiera[0][5] = new Alfiere(Casella(0,5),Pezzo::Colore::bianco);

  scacchiera[0][3] = new Regina(Casella(0,3),Pezzo::Colore::bianco);
  scacchiera[0][4] = new Re(Casella(0,4),Pezzo::Colore::bianco);

  //inizializzazione variabile Re_bianco
  re_bianco = scacchiera[0][4];

  //inizializzazione di pedoni bianchi
  constexpr int RIGA_PEDONI_BIANCHI = 1;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_BIANCHI][i] = new Pedone(Casella(RIGA_PEDONI_BIANCHI, i), Pezzo::Colore::bianco);
  }

  //inizializzazione vettore contenente i pezzi bianchi ancora vivi
  for(int i = 0; i < COLONNE; i++) {
    for(int j = 0; j < 2; j++)
      pezzi_bianchi.push_back(scacchiera[j][i]);   
  }  

  //inizializzazione vari puntatori caselle nere
  scacchiera[7][0] = new Torre(Casella(7,0),Pezzo::Colore::nero);
  scacchiera[7][7] = new Torre(Casella(7,7),Pezzo::Colore::nero);

  scacchiera[7][1] = new Cavallo(Casella(7,1),Pezzo::Colore::nero);
  scacchiera[7][6] = new Cavallo(Casella(7,6),Pezzo::Colore::nero);

  scacchiera[7][2] = new Alfiere(Casella(7,2),Pezzo::Colore::nero);
  scacchiera[7][5] = new Alfiere(Casella(7,5),Pezzo::Colore::nero);

  scacchiera[7][3] = new Regina(Casella(7,3),Pezzo::Colore::nero);
  scacchiera[7][4] = new Re(Casella(7,4),Pezzo::Colore::nero);

  //inizializzazione variabile di scacchiera che contiene posizione del re nero
  re_nero = scacchiera[7][4];

  //inizializzazione pedoni neri
  constexpr int RIGA_PEDONI_NERI = 6;
  for(int i = 0; i < COLONNE; i++) {
    scacchiera[RIGA_PEDONI_NERI][i] = new Pedone(Casella(RIGA_PEDONI_NERI, i), Pezzo::Colore::nero);
  }

  //inizializzazione vettore contenente i pezzi neri ancora vivi
  for(int i = 0; i < COLONNE; i++) {
    for(int j = 7; j > 5; j--)
      pezzi_neri.push_back(scacchiera[j][i]);   
  } 

  //inizializzo a 0 il contatore delle mosse
  conta_mosse = 0; 
  mosse_totali = 0;
}

Scacchiera::~Scacchiera() {
  //delete di tutti i puntatori agli oggetti non mangiati
  for(int i = 0; i < RIGHE; i++) {
    for(int j = 0; j < COLONNE; j++) {
      if(scacchiera[i][j] != nullptr)
        delete scacchiera[i][j];
    }
  }

  std::ofstream documento; 
  documento.open("log.txt"); // apertura/creazione del file
  if(!documento )  // non è riuscito ad aprire il file (errore)
    return;
  
  //realizzazione del log della partita
  for(std::string s : log_mosse) {
    documento<<s;
  }

  documento.close();
}

void Scacchiera::stampa() {
  /* 
  la stampa avviene in modo specchiato rispetto a com'è veramente fatta la matrice 
  ciò consente di poter utilizzare le righe e le colonne passate dal giocatore umano
  direttamente nella matrice modificandole di un offset
  */
  for(int i = RIGHE - 1; i >= 0; i--) {
    std::cout<<i + 1<<' ';
    for(int j = 0; j < COLONNE; j++) {
      if((scacchiera[i][j] == nullptr))
        std::cout<<" ";
      else 
        std::cout<<(*scacchiera[i][j]).get_figura();
      }
      std::cout<<std::endl;
    }
  std::cout<<"  "<<"ABCDEFGH"<<std::endl;          
}

Pezzo* Scacchiera::get_casella(Casella posizione){
  //ritorna puntatore a pezzo salvato nella casella passata
  return (scacchiera[posizione.get_riga()][posizione.get_colonna()]);
}

bool Scacchiera::controllo_scacco(Pezzo::Colore colore){
  //re_scelto è un puntatore che punta al re del colore avversario
  Pezzo* re_scelto;
  colore == Pezzo::Colore::bianco ?  re_scelto = re_bianco : re_scelto = re_nero;  

  //verifica che nessun pezzo presente sulla scacchiera possa mangiare il re 
  for(int i = 0; i < RIGHE ; i++){
    for(int j = 0; j< COLONNE ; j++){
      if(scacchiera[i][j] != nullptr){ //se si ha un pezzo in questa posizione
        //se il pezzo ha colore avversario viene chiamato il metodo mossa valida con posizione di re 
        if(((*(scacchiera[i][j])).get_colore() != colore && (*(scacchiera[i][j])).simulazione_mossa((*re_scelto).get_posizione(), *this))){
          return true;
        }
      }
    }
  }
  return false;
}

bool Scacchiera::mossa(Casella posizione_in, Casella posizione_fin) {
  //caso in cui nella posizione iniziale si trova nullptr
  if(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] == nullptr)
    throw Eccezione("[Eccezione::NessunPezzo] Nella casella selezionata non c'è nessun pezzo da muovere");

  Pezzo* pezzo_mosso = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
  Pezzo* pezzo_mangiato = scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()];
  
  switch(pezzo_mosso->mossa(posizione_fin, *(this))) {
    case Pezzo::EN_PASSANT:{
      //viene effettuata la mossa
      pezzo_mangiato = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()];
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = nullptr;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;

      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())) { 
        //vengono ristabilite le posizioni di partenza
        scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
        pezzo_mosso->set_posizione(posizione_in);
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
        std::cout<<"Questa mossa mette il tuo re sotto scacco"<<std::endl;
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
        std::cout<<"Questa mossa mette il tuo re sotto scacco"<<std::endl;
        return false;
      }
      
      //aggiorno la posizione interna alla torre mossa
      if(delta_colonna == 2)
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() - 1]->set_posizione(Casella(posizione_in.get_riga(), posizione_fin.get_colonna() - 1));
      else
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna() + 1]->set_posizione(Casella(posizione_in.get_riga(), posizione_fin.get_colonna() + 1));

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
        std::cout<<"Questa mossa mette il tuo re sotto scacco"<<std::endl;
        return false;
      }

      break;
    }
    case true:{
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      //caso in cui metto il mio re sotto scacco
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        //ripristinate le condizioni iniziali
        scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
        pezzo_mosso->set_posizione(posizione_in);
        std::cout<<"Questa mossa mette il tuo re sotto scacco"<<std::endl;
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
    conta_mosse = -1;

    //il pezzo che è stato mangiato viene rimosso dal rispettivo vettore pezzi_***
    if(pezzo_mangiato->get_colore() == Pezzo::Colore::bianco) 
      pezzi_bianchi.erase(std::find(pezzi_bianchi.begin(), pezzi_bianchi.end(), pezzo_mangiato));
    if(pezzo_mangiato->get_colore() == Pezzo::Colore::nero) 
      pezzi_neri.erase(std::find(pezzi_neri.begin(), pezzi_neri.end(), pezzo_mangiato));
  }

  //se il pezzo mosso è un re si blocca la possibilità di fare l'arrocco
  if(tolower(pezzo_mosso->get_figura()) == 'r' || tolower(pezzo_mosso->get_figura()) == 't')
    static_cast<Torre*>(pezzo_mosso)->invalido_arrocco();
  
  //se si muove un pedone viene azzerato il contatore delle mosse
  if(tolower(pezzo_mosso->get_figura()) == 'p'){
    conta_mosse = 0;
    //effettua promozione dei pedoni a donna se possibile
    promuovi(pezzo_mosso);
  }
  else
    conta_mosse++;

  //mossa valida fatta, aggiorno il contatore
  mosse_totali++;

  //inserimento mossa nel log generando una stringa che indica la mossa
  std::string mossa_testuale;
  mossa_testuale.append(1, posizione_in.get_riga()+1+'0');
  mossa_testuale.append(1, posizione_in.get_colonna()+'A');
  mossa_testuale.append(1, ' ');
  mossa_testuale.append(1, posizione_fin.get_riga()+1+'0');
  mossa_testuale.append(1, posizione_fin.get_colonna()+'A');
  mossa_testuale.append(1, '\n');
  log_mosse.push_back(mossa_testuale);
    
  return true;

}

bool Scacchiera::scaccomatto(Pezzo::Colore colore) {
  return false;
}


void Scacchiera::promuovi(Pezzo* pedone) { // OTTIMIZZATA
  //promozione bianchi
  if(pedone->get_posizione().get_riga() == 7) {
    int riga_pedone = pedone->get_posizione().get_riga();
    pezzi_bianchi.erase(std::find(pezzi_bianchi.begin(), pezzi_bianchi.end(), pedone));
    delete pedone; //cancellata dalla memoria dinamica
    scacchiera[7][riga_pedone] = new Regina(Casella(7,riga_pedone), Pezzo::Colore::bianco);
  }

  //promozione neri
  if(pedone->get_posizione().get_riga() == 0) {
      int riga_pedone = pedone->get_posizione().get_riga();
      pezzi_neri.erase(std::find(pezzi_neri.begin(), pezzi_neri.end(), pedone));
      delete pedone; //cancellata dalla memoria dinamica
      scacchiera[0][riga_pedone] = new Regina(Casella(0,riga_pedone), Pezzo::Colore::nero);
    }
}


std::vector<Casella> Scacchiera::mosse_possibili(Casella posizione_pezzo){ // DA OTTIMIZZARE
  std::vector<Casella> v;
  for(int i = 0; i < RIGHE; i++) {
    for(int j = 0; j < COLONNE; j++) {
      Pezzo* pezzo_mosso = scacchiera[posizione_pezzo.get_riga()][posizione_pezzo.get_colonna()];
      if(pezzo_mosso != nullptr && pezzo_mosso->simulazione_mossa(Casella(i,j), *(this)) == true)
        v.push_back(Casella(i,j));
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
            if(static_cast<Pedone*>(pezzo_corrente)->get_mossa_salto() == mosse_totali - 1)
              temp.push_back('f');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;
          
          case 'P': //caso di pedone nero
            if(static_cast<Pedone*>(pezzo_corrente)->get_mossa_salto() == mosse_totali - 1)
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

bool Scacchiera::stallo(Pezzo::Colore colore){ // OTTIMIZZATO 
  if(colore == Pezzo::Colore::bianco)
  {
    for(int i = 0; i<pezzi_bianchi.size(); i++)
      if(pezzi_bianchi[i]->bloccato(*this))
        return false;
        
  }
  else{
    for(int i = 0; i<pezzi_neri.size(); i++)
      if(pezzi_bianchi[i]->bloccato(*this))
        return false;
  }
  return true;
}

int Scacchiera::get_ripetizioni_scacchiera(){
  return mappa_posizioni[this->stringa_per_mappa()];
}

void Scacchiera::inserisci_scacchiera(){
  mappa_posizioni.insert(std::pair<std::string, int>(this->stringa_per_mappa(), get_ripetizioni_scacchiera()));
}

bool Scacchiera::simulazione_mossa(Casella posizione_in, Casella posizione_fin) {
  //caso in cui nella posizione iniziale si trova nullptr
  if(scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] == nullptr)
    throw Eccezione("[Eccezione::NessunPezzo] Nella casella selezionata non c'è nessun pezzo da muovere");

  bool mossa = true;

  Pezzo* pezzo_mosso = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
  Pezzo* pezzo_mangiato = scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()];
  
  switch(pezzo_mosso->mossa(posizione_fin, *(this))) {
    case Pezzo::EN_PASSANT:{
      //viene effettuata la mossa
      pezzo_mangiato = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()];
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = nullptr;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;

      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        mossa = false;
      }

      //vengono ristabilite le posizioni di partenza
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
      pezzo_mosso->set_posizione(posizione_in);
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
      break;
    }
    case Pezzo::ARROCCO:{
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
      //caso in cui metti sotto scacco il tuo re
      if(controllo_scacco(pezzo_mosso->get_colore())){
        mossa = false;
      }
      
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
      break;
    }
    case Pezzo::SALTO_PEDONE:{
      //modificata scacchiera
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      
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
      //caso in cui metto il mio re sotto scacco
      if(controllo_scacco(pezzo_mosso->get_colore())) {
        mossa = false;
      }

      //ripristinate le condizioni iniziali
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
      pezzo_mosso->set_posizione(posizione_in);
      break;
    }
    case false:{
      mossa = false;
      break;
    }
  }
  return mossa;
}