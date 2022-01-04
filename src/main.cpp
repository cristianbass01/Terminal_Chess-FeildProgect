#include <iostream>

#include "./../include/scacchiera.h"
#include "./../include/umano.h"

int main() {
  Scacchiera test;
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

  bool patta = false;
  bool scaccomatto = false;
  bool stallo = false;
  Pezzo::Colore vincitore;

  try{
    if(colore) // se giocatore 1 ha i neri, allora faccio giocare prima giocatore 2
      giocatore_2.gioca();
  }
  catch(Eccezione e){
    if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0)
      giocatore_1.ricevuta_richiesta_patta();
  }

  while(!scaccomatto && !patta)
  {
    try{
      giocatore_1.gioca();
    }
    catch(Eccezione e){
      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        patta = giocatore_2.ricevuta_richiesta_patta();

      if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto 
        scaccomatto = true;
        vincitore = giocatore_1.get_colore();
      }
    }

    if(scaccomatto || patta)
      break;

    try
    {
      giocatore_2.gioca();
    }
    catch(Eccezione e)
    {
      if((e.errore()).compare("[Eccezione::Richiesta_Patta]") == 0) // gestione richiesta patta
        patta = giocatore_1.ricevuta_richiesta_patta();

      if((e.errore()).compare("[Eccezione::Scaccomatto]") == 0){ // gestione scaccomatto 
        scaccomatto = true;
        vincitore = giocatore_1.get_colore();
      }
    }
  }

  if(scaccomatto){
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

  if(patta){
    std::cout << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << "*       La partita si è conclusa con una patta                *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;
  }
  return 0;
}