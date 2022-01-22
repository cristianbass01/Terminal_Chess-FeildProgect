/*
  Cinel Giovanni 2000147
*/
#ifndef PEZZO_H
#define PEZZO_H

#include "casella.h"


class Scacchiera; 

//classe virtuale pura
class Pezzo {

  public:
    
    //enum dei colori dei pezzi
    enum class Colore {
      bianco, nero        //bianco=0, nero=1
    };

    //metodo virtuale che sposta il pezzo
    virtual int mossa(Casella posizione, Scacchiera& scacchiera); 

    //metodo che ritorna la figura
    const char get_figura() const { return figura_; }
    
    //metodo che restituisce il colore del pezzo
    Pezzo::Colore get_colore() const { return colore_; }

    //metodo che restituisce la casella del pezzo
    Casella get_posizione() const {return posizione_; }

    //metodo che imposta la posizione del pezzo
    void set_posizione(Casella posizione) {posizione_ = posizione;}

  public:

    //costanti che indicano il tipo di mossa eseguita
    static constexpr int EN_PASSANT {2};
    static constexpr int SALTO_PEDONE {3};
    static constexpr int ARROCCO {4};
    static constexpr int SCACCO_AVVERSARIO {5};

  protected:
    //posizione del pezzo nella scacchiera
    Casella posizione_;
        
    //figura che viene rappresentata nella scachiera
    char figura_; 

    //colore del pezzo
    Colore colore_;

  protected:

    //metodo virtuale puro che controlla se la mossa è valida (SENZA controllo scacco)
    virtual int mossa_valida(Casella posizione, Scacchiera& scacchiera) = 0; 
};

//HELPER FUNCTION

//overriding operatore << che torna la figura 
std::ostream& operator<<(std::ostream& os, const Pezzo& temp);
#endif  //PEZZO_H