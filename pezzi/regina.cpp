#include "regina.h"

Regina::Regina(int rig, int col, Colore color) {
  riga = rig;
  colonna = col;
  colore = color;
  if(colore == Colore::nero)
    figura = 'D';
  else 
    figura = 'd';
}