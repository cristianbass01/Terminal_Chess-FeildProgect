#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Regina : public Pezzo{
  public:
     Regina(int rig, int col, int color) {
      riga = rig;
      colonna = col;
      colore = Pezzo::Colore(color);
      if(color == 0)
        figura = 'd';
      else figura = 'D';
    }
}

#endif // REGINA_H