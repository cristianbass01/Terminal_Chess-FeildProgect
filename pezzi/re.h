#ifndef RE_H
#define RE_H

#include "pezzo.h"

class Re : public Pezzo {
  public:
    Re(int rig, int col, Pezzo::Colore color) { 
      riga = rig;
      colonna = col;
      colore = color;
      if(colore == Colore::nero)
        figura = 'R';
      else
        figura = 'r';
    }
    void mossa(int r, int c) override {} //metodo virtuale puro che sposta il pezzo
    bool mossa_valida(int r, int c) override {return false;}
};

#endif // RE_H