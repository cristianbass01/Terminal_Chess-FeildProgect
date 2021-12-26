#ifndef REGINA_H
#define REGINA_H

#include "pezzo.h"

class Regina : public Pezzo{
  public:
     Regina(int rig, int col, int color) {
      riga = rig;
      colonna = col;
      colore = Pezzo::Colore(color);
      if(colore == Colore::nero)
        figura = 'D';
      else 
        figura = 'd';
    }
};

#endif // REGINA_H