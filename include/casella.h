#ifndef CASELLA_H
#define CASELLA_H

#include "eccezione.h"

class Casella{
    int riga_;
    int colonna_;
  public:
    //costruttore
    Casella() {}
    Casella(int riga, int colonna);
    Casella(const Casella&);
    
    //assegnatore di copia
    Casella& operator=(const Casella& pos);

    //metodi base
    int get_riga() {return riga_;}
    int get_colonna() {return colonna_;}
    void set_riga(int riga);
    void set_colonna(int colonna);
    void set(int riga, int colonna);
};

#endif // CASELLA_H
