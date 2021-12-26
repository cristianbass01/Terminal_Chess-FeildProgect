#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo {
  public:
    //PERCHE' NON FUNZIONA
    //Alfiere(int rig, int col) : riga{rig}, colonna {col}{ }
    Alfiere(int rig, int col) {
      riga = rig;
      colonna = col;
    }
};

#endif // ALFIERE_H
