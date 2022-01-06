#ifndef CASELLA_H
#define CASELLA_H

#include "eccezione.h"

class Casella{

    //salvataggio riga
    int riga_;

    //salvataggio colonna
    int colonna_;
    
  public:
    //costruttore di default
    Casella() {}

    //costruttore con riga e colonna (lancia [Eccezione::CasellaErrata])
    Casella(int riga, int colonna);

    //costruttore di copia
    Casella(const Casella&);
    
    //assegnatore di copia
    Casella& operator=(const Casella& pos);

  //metodi base
    //restituisce la riga
    int get_riga() {return riga_;}

    //restituisce la colonna
    int get_colonna() {return colonna_;}

    //imposta la riga (lancia [Eccezione::CasellaErrata])
    void set_riga(int riga);

    //imposta la colonna (lancia [Eccezione::CasellaErrata])
    void set_colonna(int colonna);

    //imposta riga e colonna (lancia [Eccezione::CasellaErrata])
    void set(int riga, int colonna);
};

#endif // CASELLA_H
