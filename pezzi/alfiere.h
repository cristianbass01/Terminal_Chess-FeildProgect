#ifndef ALFIERE_H
#define ALFIERE_H

#include "pezzo.h"

class Alfiere : public Pezzo {
  public:
    Alfiere(int rig, int col, Colore color) {
      colore = color;
      riga = rig;
      colonna = col;
      if(colore == Colore::nero)
        figura = 'A';
      else
        figura = 'a';
    }
};

#endif // ALFIERE_H
