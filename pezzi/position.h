#ifndef CASELLA_H
#define CASELLA_H

class Casella{
    int riga;
    int colonna;
  public:
    //costruttore
    Casella(int r, int c);
    
    //metodi base
    int get_riga() {return riga;}
    int get_colonna() {return colonna;}
    void set_riga(int r);
    void set_colonna(int c);
};

#endif // 