#include <iostream>

#include "./../include/scacchiera.h"

int main() {
  Scacchiera test;
  test.stampa();
  std::cout<< "Gianluchino"<<std::endl;
  Casella cavallo(0,1);  
  Casella cavallo1(2,2);
  if(test.mossa(cavallo, cavallo1))
    std::cout<<"cazzo"<<std::endl;
  else
    std::cout<< "Gianluchino"<<std::endl;
  test.stampa();
  Casella alfiere(0,2);  
  Casella alfiere1(3,5);
  test.mossa(alfiere, alfiere1);
  test.stampa();
}