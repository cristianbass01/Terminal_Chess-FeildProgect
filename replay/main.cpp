/*
  Nordio Gianluca 2007959
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <chrono>
#include <thread>

#include "./../scacchiera/include/scacchiera.h"
#include "./../scacchiera/include/umano.h"



int main(int argc, char *argv[]) {

  // per trasformare da lettera a numero di colonna
  static constexpr int a = 97; 

  //verifica il numero di argomenti passati da riga di comando
  if(argc < 3 || argc > 4){
    std::cout << "[Eccezione::Numero_Di_Argomenti_Errato]"<< std::endl;
    throw Eccezione("[Eccezione::Numero_Di_Argomenti_Errato]");
  }
  
  //argv[0] è il nome del programma quindi usiamo argv[1]

  //verifica che l'argomento iniziale sia corretto
  if(tolower(*argv[1]) != 'v' && tolower(*argv[1]) != 'f' ) {
    std::cout << "[Eccezione::Argomento_Non_Valido]"<< std::endl;
    throw Eccezione("[Eccezione::Argomento_Non_Valido]");
  }
  
  //caso in cui su usa scrittura su file, ma non vengono passati i nomi di due file
  if(tolower(*argv[1]) == 'f' && argc != 4){
    std::cout << "[Eccezione::Numero_Di_Argomenti_Errato]"<< std::endl;
    throw Eccezione("[Eccezione::Numero_Di_Argomenti_Errato]");
  }

  //caso in cui si fa la stampa a video, ma non viene passato un file log da cui leggere
  if(tolower(*argv[1]) == 'v' && argc != 3){
    std::cout << "[Eccezione::Numero_Di_Argomenti_Errato]"<< std::endl;
    throw Eccezione("[Eccezione::Numero_Di_Argomenti_Errato]");
  }
  
  Scacchiera scacchiera; 
  
  //lista in cui vengono inserite tutte le mosse lette da file
  std::list<std::string> lista_mosse;

  //apertura del file da cui leggere le mosse
  std::ifstream log_input;
  log_input.open(argv[2]);

  //riempimento della lista delle mosse
  if(log_input.is_open()) {
    //lettura dal file usando ifstream
    std::string mossa;   
    while(getline(log_input, mossa)) {
      lista_mosse.push_back(mossa);
    }
    log_input.close();
  }   
  else {
    std::cout << "Impossibile aprire il file di input"<< std::endl;
    throw Eccezione("File_Non_Trovato");
  }

  std::ofstream log_output;
  //nel caso si abbia come argomento f un file viene aperto in scrittura
  if(tolower(*argv[1]) == 'f') {
    //apertura file di output
    log_output.open(argv[3], std::ofstream::out | std::ofstream::trunc);
	  if(!log_output.is_open()) {
      std::cout << "Impossibile aprire il file di output" << std::endl;
      throw Eccezione("File_Non_Trovato");
    }
  }
  
  //stringa che conterrà il messaggio che indica il motivo per cui è finita la partita
  std::string fine_partita; 

  try {
    Pezzo::Colore colore = Pezzo::Colore::bianco;
    int num_mosse = 0;
    while(!lista_mosse.empty()) { //fa proseguire partita finchè ci sono mosse

      if(num_mosse % 2 == 0) //caso in cui la mossa è del bianco
        colore = Pezzo::Colore::bianco;
      else //caso in cui la mossa è del bianco
        colore = Pezzo::Colore::nero;

      //inserita la mossa corrente in stringa mossa
      std::string mossa = lista_mosse.front();
      lista_mosse.pop_front();

      //verifica che il formato di mossa sia corretto
      if(mossa.size() != 5 || mossa[2] != ' ' )
        throw Eccezione("[Eccezione::Log_Errato]");
      
      //tutte lettere in formato minuscolo
      for(int i = 0; i<mossa.size(); i++)
        mossa[i] = tolower(mossa[i]);
      
      //creazione colonna iniziale
      int colonna_iniziale = mossa[0] - a; // in questo modo parto da a = 0 come colonna
      int riga_iniziale = mossa[1] - 49;
      Casella iniziale(riga_iniziale, colonna_iniziale); 
      
      //creazione colonna finale
      int colonna_finale = mossa[3] - a; // in questo modo parto da a = 0 come colonna
      int riga_finale = mossa[4] - 49;
      Casella finale = Casella(riga_finale, colonna_finale);

      //caso in cui si cerca di muovere un pezzo del colore opposto
      if(scacchiera.get_casella(iniziale)->get_colore() != colore)
        throw Eccezione("[Eccezione::Log_Errato]");

      //caso in cui viene selezionato una casella che non ha un pezzo
      if(scacchiera.get_casella(iniziale) == nullptr) 
        throw Eccezione("[Eccezione::Log_Errato]");

      //faccio la mossa
      if(!scacchiera.mossa(iniziale, finale)) 
        throw Eccezione("[Eccezione::Log_Errato]");

      //gestione del caso della promozione
      int mossa_promozione = scacchiera.promuovi(finale); //mossa in cui viene fatta la promozione
      if(mossa_promozione >= 0){
        try{
          //viene salvata la mossa corrente in mossa
          mossa = lista_mosse.front();
          lista_mosse.pop_front();
        }
        catch(...){ //caso in cui la partita finisca per fine mosse e non per altri motivi
          throw Eccezione("[Eccezione::Log_Errato]");
        }

        //verifica che il formato di mossa sia corretto
        if(mossa.size() != 5 || mossa[2] != ' ' )
          throw Eccezione("[Eccezione::Log_Errato]");

        //tutte lettere in formato minuscolo
        for(int i = 0; i<mossa.size(); i++)
          mossa[i] = tolower(mossa[i]);

        int colonna_promozione = mossa[0] - a; // in questo modo parto da a = 0 come colonna
        int riga_promozione = mossa[1] - 49;

        //gestione promozione
        if(colonna_promozione != mossa_promozione)
          throw Eccezione("[Eccezione::Log_Errato]");

        if(mossa[3] == '='){
          char figura_pezzo = mossa[4];
          scacchiera.fine_promozione(figura_pezzo, colore, colonna_promozione);
        }
        else
          throw Eccezione("[Eccezione::Log_Errato]");
      }

      
      if(scacchiera.pezzi_insufficienti())
        throw Eccezione("[Eccezione::Patta_Materiale]");
    
      //caso in cui bisogna stampare a video
      constexpr int NUMERO_MILLISECONDI_ATTESA = 1000;
      if(tolower(*argv[1]) == 'v') { 
        std::this_thread::sleep_for(std::chrono::milliseconds(NUMERO_MILLISECONDI_ATTESA));
        scacchiera.stampa();
      }
      else { //caso in cui bisogna stampare da file
        log_output << scacchiera << std::endl;
      }
      
      Pezzo::Colore colore_avversario = colore == Pezzo::Colore::bianco ? Pezzo::Colore::nero : Pezzo::Colore::bianco;
      //controlla che il giocatore non sia in stallo
      if(scacchiera.controllo_scacco(colore_avversario) == false)
        if(scacchiera.stallo(colore_avversario)) 
          throw Eccezione("[Eccezione::Patta_Stallo]");
      //verifica se si tratta di scaccomatto
      std::string vittoria;
      if(scacchiera.scaccomatto(colore_avversario)) {
        //stampa su file o a video che giocatore ha vinto
        vittoria += "Ha vinto il giocatore ";
        if(colore == Pezzo::Colore::bianco)
          vittoria += "bianco!\n";
        else
          vittoria += "nero!\n";
        
        if(tolower(*argv[1]) == 'v') 
          std::cout<<vittoria;
        else 
          log_output<<vittoria;
      
        throw Eccezione("[Eccezione::Scaccomatto]");
      }
      
      //verifica che non vanga superato il limite di mosse senza pezzi mangiati o pedoni mossi
      if(scacchiera.get_conta_mosse() >= 50)
        throw Eccezione("[Eccezione::Patta_Mosse]");
        num_mosse++;
    }
  }
  catch(Eccezione e){
    if((e.errore()).compare("[Eccezione::Log_Errato]") == 0) // fine partita perché formato log non corretto
      fine_partita = "Log_Errato";

    if((e.errore()).compare("[Eccezione::CasellaErrata]") == 0) // fine partita perché formato log non corretto
      fine_partita = "Log_Errato";

    if((e.errore()).compare("[Eccezione::Patta_Stallo]") == 0) // gestione patta per stallo
      fine_partita = "Patta_Stallo";

    if((e.errore()).compare("[Eccezione::Patta_Materiale]") == 0) // gestione patta per materiale insufficiente 
      fine_partita = "Patta_Insufficienza di materiale";
    
    if((e.errore()).compare("[Eccezione::Patta_Mosse]") == 0) // gestione patta mossa
      fine_partita = "Patta_Gioco fermo (mosse)";

    if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto 
      fine_partita = "Scaccomatto";
    }
  }

  //caso in cui la partita finisce perchcé non ci sono più mosse
  if(fine_partita.length() == 0)
    fine_partita = "fine mosse";

  //stampa a video se si è in modalità video
  if(tolower(*argv[1]) == 'v'){
    std::cout << "Partita conclusa per: "<< fine_partita << std::endl;
  }
  else { //stampa su file se si è in modalita file
    log_output << "Partita conclusa per: "<< fine_partita << std::endl;
    log_output.close();
  }

  return 0;
}
