#include "casella.h"

Casella::Casella(int r, int c){
  if((r<0 || r>7) || (c<0 || c>7)) throw CasellaErrata();
  else{
    riga = r;
    colonna = c;
  }
}

void Casella::set_riga(int r){
  if(r<0 || r>7) throw CasellaErrata();
  else
    riga = r;
}
    
void Casella::set_colonna(int c){
  if(c<0 || c>7) throw CasellaErrata();
  else
    colonna = c;
}

void Casella::set(int r, int c){
  if((r<0 || r>7) || (c<0 || c>7)) throw CasellaErrata();
  else{
    riga = r;
    colonna = c;
  }
}