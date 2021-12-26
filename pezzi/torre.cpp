#include "torre.h"

Torre::Torre(int rig, int col, Colore color) {
  riga = rig;
  colonna = col;
  colore = color;
  if(colore == Colore::nero)
    figura = 'T';
  else 
    figura = 't';
}