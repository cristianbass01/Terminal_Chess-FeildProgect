#ifndef RE_H_
#define RE_H_

#include "pezzo.h"

class Re : public Pezzo {
  public:
    Re(int rig, int col) : riga{rig}, colonna{col} {  }
}

#endif // RE_H_