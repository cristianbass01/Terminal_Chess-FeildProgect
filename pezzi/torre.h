#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo{
  public:
     Torre(int rig, int col, Colore color);
};

#endif // TORRE_H
