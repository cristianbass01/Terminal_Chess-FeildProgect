#include <iostream>
#include <string.h>
#include <fstream>
#include <list>

//DA CONTROLLARE
#include <chrono>
#include <thread>

#include "./include/scacchiera.h"
#include "./include/umano.h"



int main(int argc, char *argv[]) {

  // per trasformare da lettera a numero di colonna
  static constexpr int a = 97; 

  //verifica il numero di argomenti passati da riga di comando
  if(argc < 3 || argc > 4)
    throw Eccezione("[Eccezione::Numero_Di_Argomenti_Errato");
  
  //argv[0] è il nome del programma quindi usiamo argv[1]

  //verifica che l'argomento iniziale sia corretto
  if(tolower(*argv[1]) != 'v' && tolower(*argv[1]) != 'f' ) 
    throw Eccezione("[Eccezione::Argomento_Non_Valido]");
  
  Scacchiera scacchiera_; 
  
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
    std::cout << "Impossibile apire il file";
    throw Eccezione("File_Non_Trovato");
  }
  
  try {
    //caso partita stampata a video
    if(tolower(*argv[1]) == 'v') { 
      Pezzo::Colore colore_ = Pezzo::Colore::bianco;
      int num_mosse = 0;
      while(!lista_mosse.empty()) { //fa proseguire partita finchè ci sono mosse

        //settato colore sulla base di chi numero di mossa si tratta
        if(num_mosse % 2 == 0) //caso in cui la mossa è del bianco
          colore_ = Pezzo::Colore::bianco;
        else //caso in cui la mossa è del bianco
          colore_ = Pezzo::Colore::nero;

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

        //creazione colonna finale
        int colonna_finale = mossa[3] - a; // in questo modo parto da a = 0 come colonna
        int riga_finale = mossa[4] - 49;

        Casella iniziale(riga_iniziale, colonna_iniziale); 
        Casella finale(riga_finale, colonna_finale);

        //controlla che il giocatore non sia in stallo
        if(scacchiera_.stallo(colore_)) 
          throw Eccezione("[Eccezione::Patta_Stallo]");
        
        //caso in cui viene selezionato una casella che non ha un pezzo
        if(scacchiera_.get_casella(iniziale) == nullptr) 
          throw Eccezione("[Eccezione::Log_Errato]");
        
        //caso in cui si cerca di muovere un pezzo del colore opposto
        if(scacchiera_.get_casella(iniziale)->get_colore() != colore_)
          throw Eccezione("[Eccezione::Log_Errato]");
        
        if(!scacchiera_.mossa(iniziale, finale)) 
          throw Eccezione("[Eccezione::Log_Errato]");
        
        if(scacchiera_.pezzi_insufficienti())
          throw Eccezione("[Eccezione::Patta_Insufficenza_di_Pezzi]");
        
        constexpr int NUMERO_MILLISECONDI_ATTESA = 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(NUMERO_MILLISECONDI_ATTESA)); 
        scacchiera_.stampa();


        //verifica che non sia scaccomatto
        Pezzo::Colore colore_avversario_ = (colore_ == Pezzo::Colore::nero) ? Pezzo::Colore::bianco : Pezzo::Colore::nero ;
        if(scacchiera_.scaccomatto(colore_avversario_)) {
          std::cout<<"Ha vinto il giocatore ";
          if(colore_ == Pezzo::Colore::bianco)
            std::cout<<"bianco!"<<std::endl;
          else
            std::cout<<"nero!"<<std::endl;
          throw Eccezione("[Eccezione::Scaccomatto]");
        }
        
        if(scacchiera_.get_conta_mosse() >= 50)
          throw Eccezione("[Eccezione::Patta_Mosse]");

        num_mosse++;
      }
    }
    //caso partita stampata su file
    else { 
      std::ofstream cout("log_output.txt");
      scacchiera_.stampa();
      cout.close();

    }
  }
  catch(Eccezione e){
    //stringa contenente il motivo della fine della partita
    std::string fine_partita; 
    if((e.errore()).compare("[Eccezione::Log_Errato]") == 0) // fine partita perché formato log non corretto
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
    
    std::cout<<"Partita conclusa per: "<<fine_partita;
  }
}