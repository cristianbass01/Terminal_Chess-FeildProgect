#ifndef CASELLA_H
#define CASELLA_H

class Casella{
    int riga;
    int colonna;
  public:
    //costruttore
    Casella(int r, int c);
    
    //Eccezione
    class CasellaErrata{};

    //metodi base
    int get_riga() {return riga;}
    int get_colonna() {return colonna;}
    void set_riga(int r);
    void set_colonna(int c);
    void set(int r, int c);
};

#endif // CASELLA_H