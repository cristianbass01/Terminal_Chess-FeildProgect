#include "cavallo.h"
Cavallo::Cavallo(int rig, int col, Colore color){
  colore = color; 
  riga = rig;
  colonna = col;
  if(colore == Colore::nero)
    figura = 'C';
  else
    figura = 'c';
}