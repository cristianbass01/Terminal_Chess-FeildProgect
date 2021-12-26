#ifndef PEZZO_H_
#define PEZZO_H_

class Pezzo { //classe virtuale pura
    public:
        void mossa(int r, int c) = 0; //metodo virtuale puro che sposta il pezzo
        bool valida(int r, int c) = 0; //metodo virtuale puro che controlla se la mossa è valida
    protected:
        //DA DECIDERE SE USARE STRUCT O NO
        int riga;
        int colonna;
        
        char figura; //contiene la figura che viene rappresentata nella scachiera
        
        class enum Colore {
            bianco, nero        // bianco=0, nero=1
        }
    }

#endif  // PEZZO_H_