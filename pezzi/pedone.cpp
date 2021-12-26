#include "pedone.h"
Pedone::Pedone(int rig, int col, Pezzo::Colore color) { 
  riga = rig;
  colonna = col;
  colore = color;
  if(colore == Colore::nero)
    figura = 'P';
  else
    figura = 'p';
}
