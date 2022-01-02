#ifndef PEZZO_H
#define PEZZO_H

#include "casella.h"

class Scacchiera; // forward declaration

class Pezzo { //classe virtuale pura
  public:
    virtual bool mossa(Casella posizione, Scacchiera& scacchiera); //metodo che sposta il pezzo

    virtual bool mossa_valida(Casella posizione, Scacchiera& scacchiera) = 0; //metodo virtuale puro che controlla se la mossa è valida
    char get_figura() { return figura_; }
    
    enum class Colore {
      bianco, nero        // bianco=0, nero=1
    };
    
    Pezzo::Colore get_colore() { return colore_; }
    Casella get_posizione() {return posizione_; }
    void set_posizione(Casella posizione) {posizione_ = posizione;}
    
  protected:
    //classe casella che contiene riga e colonna
    Casella posizione_;
        
    char figura_; //contiene la figura che viene rappresentata nella scachiera
    Colore colore_;
};
#endif  // PEZZO_H