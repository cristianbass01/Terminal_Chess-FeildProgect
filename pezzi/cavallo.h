#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(int rig, int col, Colore color){
      colore = color; 
      riga = rig;
      colonna = col;
      if(colore == Colore::nero)
        figura = 'C';
      else
        figura = 'c';
    }
};

#endif // CAVALLO_H
