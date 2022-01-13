/*
  Cinel Giovanni 2000147
*/

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

#include "./../include/scacchiera.h"
#include "./../include/umano.h"
#include "./../include/computer.h"

int main(int argc, char** argv) {
  Scacchiera test;

  //reset per i numeri randomici 
  srand(time(NULL));

  //verifica che il numero di argomenti passati da riga di comando sia corretto
  if(argc < 2 || argc > 3)
    throw Eccezione("[Eccezione::Numero_Di_Argomenti_Errato");
  
  //argv[0] è il nome del programma quindi usiamo argv[1]
  std::string arg = argv[1];

  //verifica che l'argomento iniziale sia corretto
  if(arg.compare("pc") != 0 && arg.compare("cc") != 0) 
    throw Eccezione("[Eccezione::Argomento_Non_Valido]");

  //scelta randomica dei colori dei giocatori
  bool colore = static_cast<bool>(rand() % 2);

  //creo i giocatori per la partita
  Giocatore* giocatore_1;
  Giocatore* giocatore_2;
  giocatore_1 = new Computer(&test, static_cast<Pezzo::Colore>(colore));

  //creo secondo giocatore in base al valore di passato come argomento da riga di comando
  if(arg.compare("cc") == 0){

    //caso partita computer vs computer
    giocatore_2 = new Computer(&test, static_cast<Pezzo::Colore>(!colore));
  }
  else{

    //caso partita umano vs computer
    giocatore_2 =  new Umano(&test, static_cast<Pezzo::Colore>(!colore));
  }

  std::string fine_partita = "";
  Pezzo::Colore vincitore;
  try{
    if(colore) // se giocatore 1 ha i neri, allora faccio giocare prima giocatore 2
      giocatore_2->gioca();
  }
  catch(Eccezione e){
      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        if(giocatore_1->ricevuta_richiesta_patta())
          fine_partita = "Patta_Accordo";
    if((e.errore()).compare("[Eccezione::Abbandono]") == 0){ // gestione scaccomatto 
        fine_partita = "Abbandono";
        vincitore = giocatore_1->get_colore();
    }
  }
  while(fine_partita.size() == 0)
  {
    try{
      giocatore_1->gioca();
    }
    catch(Eccezione e){
      if((e.errore()).compare("[Eccezione::Patta_Stallo]") == 0) // gestione patta per stallo
        fine_partita = "Patta_Stallo";
      if((e.errore()).compare("[Eccezione::Patta_Materiale]") == 0) // gestione patta per materiale insufficiente
        fine_partita = "Patta_Insufficienza di materiale";
      if((e.errore()).compare("[Eccezione::Patta_Posizione]") == 0) // gestione patta posizione ripetuta
        fine_partita = "Patta_Posizione ripetuta";
      if((e.errore()).compare("[Eccezione::Patta_Mosse]") == 0) // gestione patta mossa
        fine_partita = "Patta_Gioco fermo (mosse)";
      if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto
        fine_partita = "Scaccomatto";
        vincitore = giocatore_1->get_colore();
      }
    }
    
    if(arg.compare("cc") == 0 && test.get_mosse_totali() >= Computer::MAX_MOSSE)
      fine_partita = "Patta_Max mosse Computer vs Computer superate";
    
    if(fine_partita.size() != 0)
      break;
    
    try
    {
      giocatore_2->gioca();
    }
    catch(Eccezione e)
    {
      if((e.errore()).compare("[Eccezione::Patta_Stallo]") == 0) // gestione patta per stallo
        fine_partita = "Patta_Stallo";
      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        if(giocatore_1->ricevuta_richiesta_patta())
          fine_partita = "Patta_Accordo";
      if((e.errore()).compare("[Eccezione::Patta_Materiale]") == 0) // gestione patta per materiale insufficiente
        fine_partita = "Patta_Insufficienza di materiale";
      if((e.errore()).compare("[Eccezione::Patta_Posizione]") == 0) // gestione patta posizione ripetuta
        fine_partita = "Patta_Posizione ripetuta";
      if((e.errore()).compare("[Eccezione::Patta_Mosse]") == 0) // gestione patta
        fine_partita = "Patta_Gioco fermo (mosse)";
      if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto 
        fine_partita = "Scaccomatto";
        vincitore = giocatore_2->get_colore();
      }
      if((e.errore()).compare("[Eccezione::Abbandono]") == 0){ // gestione scaccomatto 
        fine_partita = "Abbandono";
        vincitore = giocatore_1->get_colore();
      }
    }
    
    if(arg.compare("cc") == 0 && test.get_mosse_totali() >= Computer::MAX_MOSSE)
      fine_partita = "Patta_Max mosse Computer vs Computer superate";
  }
  
  //gestisco le stampe per la fine della partita

  if(fine_partita.compare("Scaccomatto") == 0){
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    if(vincitore == Pezzo::Colore::bianco)
      std::cout << "*       Complimenti giocatore bianco!!                        *" << std::endl;
    else
      std::cout << "*       Complimenti giocatore nero!!                          *" << std::endl;
    std::cout << "*       Hai vinto la partita per scaccomatto                  *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
  }

  if((fine_partita.substr(0,5)).compare("Patta") == 0){
    int const FRASE_PIU_LUNGA =  strlen("Patta_Max mosse Computer vs Computer superate");
    for(int i = fine_partita.size(); i< FRASE_PIU_LUNGA; i++)
      fine_partita += " ";
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "*       Partita finita con una patta causata da:              *" << std::endl;
    std::cout << "*       ";
    std::cout << fine_partita.substr(6);
    std::cout << "               *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
  }

  if(fine_partita.compare("Abbandono") == 0){
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "*       Fine partita causa abbandono                          *" << std::endl;
    if(vincitore == Pezzo::Colore::bianco){
      std::cout << "*       Il giocatore nero ha abbandonato                      *" << std::endl;
      std::cout << "*       Complimenti giocatore bianco!!                        *" << std::endl;
    }
    else{
      std::cout << "*       Il giocatore bianco ha abbandonato                    *" << std::endl;
      std::cout << "*       Complimenti giocatore nero!!                          *" << std::endl;
    }
    std::cout << "*       Hai vinto la partita                                  *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
