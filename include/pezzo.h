#ifndef PEZZO_H
#define PEZZO_H

#include "casella.h"

// forward declaration
class Scacchiera; 

//classe virtuale pura
class Pezzo {
  public:
    //metodo virtuale che sposta il pezzo
    virtual int mossa(Casella posizione, Scacchiera& scacchiera); 

    // il pezzo ha almeno una posizione valida in cui muoversi?
    virtual bool bloccato(Scacchiera& scacchiera) = 0;

    //metodo che ritorna la figura
    const char get_figura() const { return figura_; }
    
    // enum dei colori dei pezzi
    enum class Colore {
      bianco, nero        // bianco=0, nero=1
    };
    
    //metodo che restituisce il colore del pezzo
    Pezzo::Colore get_colore() { return colore_; }

    //metodo che restituisce la casella del pezzo
    Casella get_posizione() {return posizione_; }

    //metodo che imposta la posizione del pezzo
    void set_posizione(Casella posizione) {posizione_ = posizione;}

    // overriding operatore << che torna la figura 
    friend std::ostream& operator<<(std::ostream& os, const Pezzo& temp);
    
    //costanti che indicano il tipo di mossa eseguita
    static constexpr int EN_PASSANT = 2;
    static constexpr int SALTO_PEDONE = 3;
    static constexpr int ARROCCO = 4;

  protected:
    //classe casella che contiene riga e colonna
    Casella posizione_;
        
    //contiene la figura che viene rappresentata nella scachiera
    char figura_; 

    //contiene il colore del pezzo
    Colore colore_;

    //metodo virtuale puro che controlla se la mossa è valida (SENZA controllo scacco)
    virtual int mossa_valida(Casella posizione, Scacchiera& scacchiera) = 0; 
};
#endif  // PEZZO_H