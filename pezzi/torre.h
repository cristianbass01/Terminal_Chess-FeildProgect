#ifndef TORRE_H_
#define TORRE_H_

#include "pezzo.h"

class Torre : public Pezzo{
  public:
    Torre(int rig, int col) : riga{rig}, colonna{col} {  }
};

#endif // TORRE_H_
