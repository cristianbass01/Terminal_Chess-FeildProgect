#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(int rig, int col, int color){
      colore = color; 
      riga = rig;
      colonna = col;
    }
};

#endif // CAVALLO_H
