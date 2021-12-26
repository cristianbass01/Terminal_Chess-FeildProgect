#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere: public Pezzo {
  public:
    Alfiere(int rig, int col) : riga{rig}, colonna {col}{ }
}

#endif // ALFIERE_H
