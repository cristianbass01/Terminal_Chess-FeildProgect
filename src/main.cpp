#include <iostream>
#include <string.h>

#include "./../include/scacchiera.h"
#include "./../include/umano.h"

int main() {
  Scacchiera test;
  std::cout<<test.stringa_per_mappa()<<std::endl;
  /*
  for(Pezzo* t: test.pezzi_bianchi)
    std::cout<<t->get_figura();
  std::cout<<std::endl<<std::endl;

  for(Pezzo* t: test.pezzi_neri)
    std::cout<<t->get_figura();
  std::cout<<std::endl;
  */

  Casella cavallo(0,1);  
  Casella cavallo1(2,2);
  test.mossa(cavallo, cavallo1);
  std::cout << "\n";

  test.mossa(Casella(7,1), Casella(5,2));
  test.stampa();
  std::cout << "\n";

  test.mossa(Casella(5,2), Casella(3,3));
  test.stampa();
  std::cout << "\n";
  

  test.mossa(Casella(3,3), Casella(1,4));
  test.stampa();
  std::cout << "\n";

  test.mossa(Casella(1,1), Casella(3,1));
  test.stampa();
  std::cout << "\n";

  test.mossa(Casella(0,3), Casella(1,4));
  test.stampa();
  std::cout << "\n";

  test.mossa(Casella(0,2), Casella(2,0));
  test.stampa();
  std::cout << "\n";

  //Casella alfiere(0,5);  
  //Casella alfiere1(1,4);
  //test.mossa(alfiere, alfiere1);
  test.stampa();
  std::cout << "\n";
  

  
  bool colore = static_cast<bool>(rand() % 2); //scelta randomica dei colori dei giocatori
  Umano giocatore_1(&test, static_cast<Pezzo::Colore>(colore));
  Umano giocatore_2(&test, static_cast<Pezzo::Colore>(!colore));

  std::string fine_partita = "";
  Pezzo::Colore vincitore;

  try{
    if(colore) // se giocatore 1 ha i neri, allora faccio giocare prima giocatore 2
      giocatore_2.gioca();
  }
  catch(Eccezione e){
      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        if(giocatore_2.ricevuta_richiesta_patta())
          fine_partita = "Patta_Accordo";
    
    if((e.errore()).compare("[Eccezione::Abbandono]") == 0){ // gestione scaccomatto 
        fine_partita = "Abbandono";
        vincitore = giocatore_2.get_colore();
    }
  }

  while(fine_partita.size() == 0)
  {
    try{
      giocatore_1.gioca();
    }
    catch(Eccezione e){
      if((e.errore()).compare("[Eccezione::Patta_Stallo]") == 0) // gestione patta per stallo
        fine_partita = "Patta_Stallo";

      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        if(giocatore_2.ricevuta_richiesta_patta())
          fine_partita = "Patta_Accordo";

      if((e.errore()).compare("[Eccezione::Patta_Materiale]") == 0) // gestione patta per materiale insufficiente NON FATTA
        fine_partita = "Patta_Insufficienza di materiale";
      
      if((e.errore()).compare("[Eccezione::Patta_Posizione]") == 0) // gestione patta posizione ripetuta NON FATTA
        fine_partita = "Patta_Posizione ripetuta";

      if((e.errore()).compare("[Eccezione::Patta_Mosse]") == 0) // gestione patta
        fine_partita = "Patta_Gioco fermo (mosse)";

      if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto NON FATTA
        fine_partita = "Scaccomatto";
        vincitore = giocatore_1.get_colore();
      }

      if((e.errore()).compare("[Eccezione::Abbandono]") == 0){ // gestione abbandono partita
        fine_partita = "Abbandono";
        vincitore = giocatore_2.get_colore();
      }
    }

    if(fine_partita.size() != 0)
      break;

    try
    {
      giocatore_2.gioca();
    }
    catch(Eccezione e)
    {
      if((e.errore()).compare("[Eccezione::Patta_Stallo]") == 0) // gestione patta per stallo
        fine_partita = "Patta_Stallo";

      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        if(giocatore_2.ricevuta_richiesta_patta())
          fine_partita = "Patta_Accordo";

      if((e.errore()).compare("[Eccezione::Patta_Materiale]") == 0) // gestione patta per materiale insufficiente
        fine_partita = "Patta_Insufficienza di materiale";
      
      if((e.errore()).compare("[Eccezione::Patta_Posizione]") == 0) // gestione patta posizione ripetuta
        fine_partita = "Patta_Posizione ripetuta";

      if((e.errore()).compare("[Eccezione::Patta_Mosse]") == 0) // gestione patta
        fine_partita = "Patta_Gioco fermo (mosse)";

      if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto 
        fine_partita = "Scaccomatto";
        vincitore = giocatore_2.get_colore();
      }

      if((e.errore()).compare("[Eccezione::Abbandono]") == 0){ // gestione scaccomatto 
        fine_partita = "Abbandono";
        vincitore = giocatore_1.get_colore();
      }
    }
  }

  if(fine_partita.compare("Scaccomatto") == 0){
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    if(vincitore == Pezzo::Colore::bianco)
      std::cout << "*       Complimenti giocatore bianco!!                        *" << std::endl;
    else
      std::cout << "*       Complimenti giocatore nero!!                          *" << std::endl;
    std::cout << "*                                                             *" << std::endl;
    std::cout << "*       Hai vinto la partita per scaccomatto                  *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
  }

  if((fine_partita.substr(0,4)).compare("Patta") == 0){
    int const FRASE_PIU_LUNGA =  strlen("Patta_Insufficienza di materiale");
    for(int i = fine_partita.size(); i< FRASE_PIU_LUNGA; i++)
      fine_partita += " ";
    
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "*       La partita si è conclusa con una patta                *" << std::endl;
    std::cout << "*       causa: ";
    std::cout << fine_partita.substr(6);
    std::cout << "               *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
  }

  if(fine_partita.compare("Abbandono") == 0){
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "*       La partita si è conclusa con un abbandono             *" << std::endl;
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