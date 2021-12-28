#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <vector>
#include <string>

class Giocatore{
  private:

  public:
    virtual void gioca() = 0; // metodo virtuale puro che fa eseguire una mossa al giocatore
};

#endif // GIOCATORE_H
