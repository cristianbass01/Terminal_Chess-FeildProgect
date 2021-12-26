#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Regina : public Pezzo{
  public:
     Regina(int rig, int col, Colore color);
};

#endif // REGINA_H