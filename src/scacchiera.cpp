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
    //se pezzo mosso è pedone azzero il contatore mosse
    
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

    //se il pezzo mosso è un re blocco la possibilità di fare l'arrocco
    if(tolower(pezzo_mosso->get_figura()) == 'r' || tolower(pezzo_mosso->get_figura()) == 't')
      static_cast<Torre*>(pezzo_mosso)->invalido_arrocco();
    //se muovo un pedone azzero il contatore delle mosse
    if(tolower(pezzo_mosso->get_figura()) == 'p')
      conta_mosse = 0;
    else
      conta_mosse++;
    return true;
  }
  return false;
}

bool Scacchiera::scaccomatto(Pezzo::Colore colore) {
  return false;
}