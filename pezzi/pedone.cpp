#include "pedone.h"

Pedone::Pedone(Casella posizione, Pezzo::Colore colore) { 
  posizione_ = posizione;
  colore_ = colore;
  if(colore == Colore::nero)
    figura_ = 'P';
  else
    figura_ = 'p';
}
