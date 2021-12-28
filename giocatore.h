#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <vector>
#include <string>

class Giocatore{
  private:
    std::vector<std::string> mosse_fatte; // da salvare nel log a fine partita

  public:
    virtual void gioca() = 0; // metodo virtuale puro che fa eseguire una mossa al giocatore

    void stampaLog();
};

#endif // GIOCATORE_H
