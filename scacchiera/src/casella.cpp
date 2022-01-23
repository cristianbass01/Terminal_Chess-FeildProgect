/*
  Bassotto Cristian 2000169
*/

#include "./../include/casella.h"

Casella::Casella(int riga, int colonna) : riga_{riga}, colonna_{colonna} {
  if((riga<0 || riga>7) || (colonna<0 || colonna>7)) 
    throw Eccezione{"[Eccezione::CasellaErrata]"};
}

Casella::Casella(const Casella& pos) : riga_{pos.riga_}, colonna_{pos.colonna_} {}

void Casella::set_riga(int riga){
  if(riga<0 || riga>7) throw Eccezione{"[Eccezione::CasellaErrata]"};
  else
    riga_ = riga;
}
    
Casella& Casella::operator=(const Casella& pos){
  riga_ = pos.riga_;
  colonna_ = pos.colonna_;
  return *this;
}

void Casella::set_colonna(int colonna){
  if(colonna<0 || colonna>7) throw Eccezione{"[Eccezione::CasellaErrata]"};
  else
    colonna_ = colonna;
}

void Casella::set(int riga, int colonna){
  if((riga<0 || riga>7) || (colonna<0 || colonna>7)) throw Eccezione{"[Eccezione::CasellaErrata]"};
  else{
    riga_ = riga;
    colonna_ = colonna;
  }
}
