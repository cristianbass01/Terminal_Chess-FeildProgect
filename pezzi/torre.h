#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo{
  public:
     Torre(int rig, int col, int color) {
      riga = rig;
      colonna = col;
      colore = Pezzo::Colore(color);
      if(color == 0)
        figura = 't';
      else figura = 'T';
    }
};

#endif // TORRE_H
