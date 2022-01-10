#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <iostream>
#include <vector> 
#include <algorithm> //incluso per poter utilizzare l'algoritmo find 
#include <map>
#include <list>
#include <fstream>

#include "pezzo.h"
#include "alfiere.h"
#include "re.h"
#include "regina.h"
#include "cavallo.h"
#include "torre.h"
#include "pedone.h"

class Scacchiera {
  public:
    //costante numeri di colonne nella scacchiera
    static constexpr int COLONNE = 8;

    //costante numero di righe nella scacchiera
    static constexpr int RIGHE = 8;

    // costruttore della scacchiera
    Scacchiera();

    //distruttore della scacchiera
    ~Scacchiera();

    //stampa la scacchiera
    void stampa(); 

    //controllo mossa fatto prima
    bool mossa(Casella posizione_in, Casella posizione_fin); 

    // simula la mossa (compreso controllo scacco)
    bool simulazione_mossa(Casella posizione_in, Casella posizione_fin);

    Pezzo* get_casella(Casella posizione) const;

    // metodo che controlla se il re è sotto scacco
    bool controllo_scacco(Pezzo::Colore colore);

    // metodo che restituisce il pezzo che causa lo scacco
    Pezzo* pezzo_scacco(Pezzo::Colore colore);

    bool scaccomatto(Pezzo::Colore colore);

    bool pezzi_insufficienti();

    int get_conta_mosse() { return conta_mosse;} 

    int get_mosse_totali() const {return mosse_totali;}

    //restituisce un vettore contentente le mosse possibili che può fare il pezzo che si
    //trova nella posizione da indicare "posizione_pezzo"
    std::vector<Casella> mosse_possibili(Casella posizione_pezzo);

    //restituisce una stringa da utilizzare nella mappa che contiene le varie disposizioni
    //della scacchiera durante la partita
    //pedone che può fare enpassant viene etichettato come F(P nero) e f(p bianco)
    //torre che può fare arrocco viene etichettata come G(T nera) e g(t bianca)
    //re che può fare arrocco viene etichettata come K(R nero) e k(r bianco)
    std::string stringa_per_mappa();
    
    //controllo che il giocatore colore non sia in stallo
    bool stallo(Pezzo::Colore colore);

    //gestione mappa
    void inserisci_scacchiera();
    int get_ripetizioni_scacchiera();
    
    //metodi che ritornano tutti i pezzi ancora in gioco di un colore
    std::vector<Pezzo*> const get_pezzi_bianchi() { return pezzi_bianchi;}
    std::vector<Pezzo*> const get_pezzi_neri() {return pezzi_neri;}

  private:
    //matrice che contiene i puntatori ai singoli pezzi e rappresenta la scacchiera
    //posizione in matrice -> posizione scacchiera - 1
    Pezzo* scacchiera[RIGHE][COLONNE]; 

    //vector contenente i puntatori a tutti i pezzi ancora presenti nella scacchiera
    std::vector<Pezzo*> pezzi_neri;
    std::vector<Pezzo*> pezzi_bianchi;

    //puntatori ai due re (servono nello scacco)
    Pezzo* re_nero;
    Pezzo* re_bianco;

    //contatore delle mosse in cui non si muove un pedone ne si mangia un pezzo
    int conta_mosse;

    //contatore delle mosse totali
    int mosse_totali;

    //metodo che verifica se è possibile promuovere qualche pedone e in caso sia possibile
    //lo fa di default a donna
    void promuovi(Pezzo* pedone);


    //mappa per tener conto delle volte in cui una posizione si ripete
    std::map<std::string, int> mappa_posizioni; 
    //lista contentente le mosse fatte durante tutta la partita
    std::list<std::string> log_mosse;

};

//HELPER FUNCTION
// overriding operatore << che torna la scacchiera in stringa 
std::ostream& operator<<(std::ostream& os, const Scacchiera& temp);


#endif // SCACCHIERA_H