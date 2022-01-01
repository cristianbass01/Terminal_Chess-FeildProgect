#include <iostream>

#include "./../include/scacchiera.h"
#include "./../include/umano.h"

int main() {
  Scacchiera test;
  test.stampa();
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


  Casella alfiere(0,5);  
  Casella alfiere1(1,4);
  test.mossa(alfiere, alfiere1);
  test.stampa();
  std::cout << "\n";

  Umano giocatore_1(&test, Pezzo::Colore::bianco);
  Umano giocatore_2(&test, Pezzo::Colore::nero);

  giocatore_1.gioca();
  giocatore_2.gioca();
  giocatore_1.gioca();
}