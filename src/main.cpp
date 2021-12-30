#include <iostream>

#include "./../include/scacchiera.h"
#include "./../include/umano.h"

int main() {
  Scacchiera test;
  test.stampa();

  Umano giocatore_1(&test, Pezzo::Colore::bianco);
  Umano giocatore_2(&test, Pezzo::Colore::nero);

  giocatore_1.gioca();
  giocatore_2.gioca();
  giocatore_1.gioca();
}