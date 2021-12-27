#include "regina.h"

Regina::Regina(Casella posizione, Colore colore) {
  posizione_ = posizione;
  colore_ = colore;
  if(colore_ == Colore::nero)
    figura_ = 'D';
  else 
    figura_ = 'd';
}