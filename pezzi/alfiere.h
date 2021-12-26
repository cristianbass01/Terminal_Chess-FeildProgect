#ifndef ALFIERE_H_
#define ALFIERE_H_

#include "pezzo.h"

class Alfiere: public Pezzo {
  public:
    Alfiere(int rig, int col) : riga{rig}, colonna {col}{ }
}

#endif // ALFIERE_H_
