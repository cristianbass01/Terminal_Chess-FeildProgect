#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo {
  public:
    Alfiere(int rig, int col, Colore color);
};

#endif // ALFIERE_H
