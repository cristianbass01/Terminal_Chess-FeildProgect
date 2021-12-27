#ifndef PEZZO_H
#define PEZZO_H

#include "./../casella.h"

class Pezzo { //classe virtuale pura
  public:
    virtual void mossa(Casella posizione) = 0; //metodo virtuale puro che sposta il pezzo
    virtual bool mossa_valida(Casella posizione) = 0; //metodo virtuale puro che controlla se la mossa è valida
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