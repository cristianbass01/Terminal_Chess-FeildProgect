#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo {
  public:
     Re(int rig, int col) {
      riga = rig;
      colonna = col;
    }
};

#endif // RE_H