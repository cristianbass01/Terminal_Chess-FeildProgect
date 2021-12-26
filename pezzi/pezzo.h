#ifndef PEZZO_H
#define PEZZO_H

class Pezzo { //classe virtuale pura
  public:
    virtual void mossa(int r, int c) = 0; //metodo virtuale puro che sposta il pezzo
    virtual bool mossa_valida(int r, int c) = 0; //metodo virtuale puro che controlla se la mossa è valida
    char get_figura() { return figura; }
  protected:
    //DA DECIDERE SE USARE STRUCT O NO
    int riga;
    int colonna;
        
    char figura; //contiene la figura che viene rappresentata nella scachiera
        
    enum class Colore {
        bianco, nero        // bianco=0, nero=1
    };
};

#endif  // PEZZO_H