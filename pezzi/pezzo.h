#ifndef PEZZO_H
#define PEZZO_H

#include "./../casella.h"
#include "./../scacchiera.h"

class Pezzo { //classe virtuale pura
  public:
    /*bool mossa(Casella posizione, Scacchiera& scacchiera) { //metodo virtuale puro che sposta il pezzo
      if(mossa_valida(posizione, scacchiera)) {
        posizione_ = posizione;
        return true;
      }
      return false;
    }
    */
    virtual bool mossa_valida(Casella posizione, Scacchiera& scacchiera) = 0; //metodo virtuale puro che controlla se la mossa è valida
    char get_figura() { return figura_; }
    enum class Colore {
      bianco, nero        // bianco=0, nero=1
    };
    
  protected:
    //classe casella che contiene riga e colonna
    Casella posizione_;
        
    char figura_; //contiene la figura che viene rappresentata nella scachiera
    Colore colore_;
};

#endif  // PEZZO_H