#ifndef CAVALLO_H
#define CAVALLO_H

#include "pezzo.h"

class Cavallo : public Pezzo {
  public:
    Cavallo(int rig, int col, Colore color);
};

#endif // CAVALLO_H
