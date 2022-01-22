/*
  Bassotto Cristian 2000169
*/

#include "./../include/casella.h"

// costruttore con riga e colonna passati come argomenti (lancia [Eccezione::CasellaErrata])
Casella::Casella(int riga, int colonna) : riga_{riga}, colonna_{colonna} {
  if((riga<0 || riga>7) || (colonna<0 || colonna>7)) 
    throw Eccezione{"[Eccezione::CasellaErrata]"};
}

//costruttore di copia
Casella::Casella(const Casella& pos) : riga_{pos.riga_}, colonna_{pos.colonna_} {}

//imposta la riga passata come argomento (lancia [Eccezione::CasellaErrata])
void Casella::set_riga(int riga){
  if(riga<0 || riga>7) throw Eccezione{"[Eccezione::CasellaErrata]"};
  else
    riga_ = riga;
}
    
//assegnatore di copia
Casella& Casella::operator=(const Casella& pos){
  riga_ = pos.riga_;
  colonna_ = pos.colonna_;
  return *this;
}

//imposta la colonna passata come argomento (lancia [Eccezione::CasellaErrata])
void Casella::set_colonna(int colonna){
  if(colonna<0 || colonna>7) throw Eccezione{"[Eccezione::CasellaErrata]"};
  else
    colonna_ = colonna;
}

//imposta riga e colonna passate come argomenti (lancia [Eccezione::CasellaErrata])
void Casella::set(int riga, int colonna){
  if((riga<0 || riga>7) || (colonna<0 || colonna>7)) throw Eccezione{"[Eccezione::CasellaErrata]"};
  else{
    riga_ = riga;
    colonna_ = colonna;
  }
}
