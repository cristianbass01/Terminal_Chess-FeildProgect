#include "alfiere.h"
Alfiere::Alfiere(int rig, int col, Colore color) {
  colore = color;
  riga = rig;
  colonna = col;
  if(colore == Colore::nero)
    figura = 'A';
  else
    figura = 'a';
}
