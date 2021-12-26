#include "re.h"
Re::Re(int rig, int col, Pezzo::Colore color) { 
  riga = rig;
  colonna = col;
  colore = color;
  if(colore == Colore::nero)
    figura = 'R';
  else
    figura = 'r';
}

