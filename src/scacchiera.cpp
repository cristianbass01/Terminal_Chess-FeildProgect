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
        if(((*(scacchiera[i][j])).get_colore() != colore && (*(scacchiera[i][j])).mossa_valida((*re_scelto).get_posizione(), *this))){
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
  
  bool mossa_valida = false;
  bool en_passant = false;
  bool arrocco_valido = false;
  try{
    mossa_valida = pezzo_mosso->mossa(posizione_fin, *(this));
  }
  catch(Eccezione e){
    if((e.errore()).compare("[Eccezione::Arrocco_valido]") == 0) //gestisce l'arrocco' 
    {
      scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
      return true;
    }
    if((e.errore()).compare("[Eccezione::EnPassant]") == 0) //gestisce l'en passant 
    {
      en_passant = true;
    }
  }


  if(mossa_valida || en_passant) {
    scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()];
    scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = nullptr;
    if(en_passant){
      pezzo_mangiato = scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()];
      scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = nullptr;
    }
    if(controllo_scacco(pezzo_mosso->get_colore())){
      scacchiera[posizione_in.get_riga()][posizione_in.get_colonna()] = pezzo_mosso;
      pezzo_mosso->set_posizione(posizione_in);
      if(en_passant){
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = nullptr;
        scacchiera[posizione_in.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
        static_cast<Pedone*>(pezzo_mangiato)->en_passant_valid_ = true;
      }
      else
        scacchiera[posizione_fin.get_riga()][posizione_fin.get_colonna()] = pezzo_mangiato;
      
      //cout da implementare con try and catch
      std::cout << "Questa mossa mette sotto scacco il tuo Re" << std::endl;
      
      return false;
    }
    
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
    if(tolower(pezzo_mosso->get_figura()) == 'p')
      conta_mosse = 0;
    else
      conta_mosse++;

    //effettua promozione dei pedoni a donna se possibile
    promuovi();

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
  return false;
}

bool Scacchiera::scaccomatto(Pezzo::Colore colore) {
  return false;
}


void Scacchiera::promuovi() {
  //promozione bianchi
  for(int i = 0; i < COLONNE; i++) {
    //caso in cui un pedone dei bianchi è arrivato nella riga 8 (7 nella matrice)
    if(scacchiera[7][i]!= nullptr && scacchiera[7][i]->get_figura() == 'p') {
      delete scacchiera[7][i]; //cancellata dalla memoria dinamica
      pezzi_bianchi.erase(std::find(pezzi_bianchi.begin(), pezzi_bianchi.end(), scacchiera[7][i]));
      scacchiera[7][i] = new Regina(Casella(7,i), Pezzo::Colore::bianco);
    }
  }

  //promozione neri
  for(int i = 0; i < COLONNE; i++) {
    //caso in cui un pedone dei neri è arrivato nella riga 1 (0 nella matrice)
    if(scacchiera[0][i]!= nullptr && scacchiera[0][i]->get_figura() == 'P') {
      delete scacchiera[0][i]; //cancellata dalla memoria dinamica
      pezzi_neri.erase(std::find(pezzi_neri.begin(), pezzi_neri.end(), scacchiera[0][i]));
      scacchiera[0][i] = new Regina(Casella(0,i), Pezzo::Colore::nero);
    }
  }
}


std::vector<Casella> Scacchiera::mosse_possibili(Casella posizione_pezzo){
  std::vector<Casella> v(1);
  for(int i = 0; i < RIGHE; i++) {
    for(int j = 0; j < COLONNE; j++) {
      Pezzo* pezzo_mosso = scacchiera[posizione_pezzo.get_riga()][posizione_pezzo.get_colonna()];
      if(pezzo_mosso != nullptr && pezzo_mosso->mossa_valida(Casella(i,j), *(this)) == true)
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
            if(static_cast<Pedone*>(pezzo_corrente)->en_passant_valid_)
              temp.push_back('f');
            else
              temp.push_back(pezzo_corrente->get_figura());
            break;
          
          case 'P': //caso di pedone nero
            if(static_cast<Pedone*>(pezzo_corrente)->en_passant_valid_)
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
  if(colore == Pezzo::Colore::bianco)
  {
    for(int i = 0; i<pezzi_bianchi.size(); i++)
      if((mosse_possibili(pezzi_bianchi[i]->get_posizione())).size() != 0)
        return false;
        
  }
  else{
    for(int i = 0; i<pezzi_neri.size(); i++)
      if((mosse_possibili(pezzi_neri[i]->get_posizione())).size() != 0)
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

