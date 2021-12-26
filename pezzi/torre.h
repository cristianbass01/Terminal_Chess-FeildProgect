#ifndef TORRE_H
#define TORRE_H

#include "pezzo.h"

class Torre : public Pezzo{
  public:
     Torre(int rig, int col, int color) {
      riga = rig;
      colonna = col;
      colore = Pezzo::Colore(color);
      if(colore == Colore::nero)
        figura = 'T';
      else 
        figura = 't';
    }
};

#endif // TORRE_H
