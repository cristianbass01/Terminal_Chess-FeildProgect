/*
  Bassotto Cristian 2000169
  Nordio Gianluca 2007959
  Cinel Giovanni 2000147
*/

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
    //numero di colonne nella scacchiera
    static constexpr int COLONNE = 8;

    //numero di righe nella scacchiera
    static constexpr int RIGHE = 8;

  public:
    //costruttore della scacchiera
    Scacchiera();

    //distruttore della scacchiera
    ~Scacchiera();

    //stampa la scacchiera
    void stampa() const; 

    //metodo che esegue la mossa
    bool mossa(Casella posizione_in, Casella posizione_fin); 

    //simula la mossa (compreso controllo scacco)
    int simulazione_mossa(Casella posizione_in, Casella posizione_fin);

    //metodo che restituisce il pezzo presente nella scacchiera alla casella passata come parametro
    Pezzo* get_casella(Casella posizione) const;

    //metodo che controlla se il re è sotto scacco
    bool controllo_scacco(Pezzo::Colore colore);

    //metodo che restituisce il pezzo che causa lo scacco
    Pezzo* pezzo_scacco(Pezzo::Colore colore);

    //metodo che controlla se il re è sotto scaccomatto
    bool scaccomatto(Pezzo::Colore colore);

    //metodo che controlla che ci siano un numero di pezzi sufficienti affinchè la partita non sia patta
    bool pezzi_insufficienti();

    //metodo che restituisce il numero di mosse eseguite dall'ultima volta che è stato mosso 
    //un pedone o mangiato un pezzo (utilizzato per il controllo della patta)
    int get_conta_mosse() const { return conta_mosse_;}

    //metodo che restituisce il numero totale di mosse eseguite
    int get_mosse_totali() const {return mosse_totali_;}

    //metodo che restituisce un vettore contentente le mosse possibili che può fare il pezzo che si
    //trova nella posizione da indicare "posizione_pezzo"
    std::vector<Casella> mosse_possibili(Casella posizione_pezzo);

    //restituisce una stringa da utilizzare nella mappa che contiene le varie disposizioni
    //della scacchiera durante la partita
    //pedone che può fare enpassant viene etichettato come F(P nero) e f(p bianco)
    //torre che può fare arrocco viene etichettata come G(T nera) e g(t bianca)
    //re che può fare arrocco viene etichettata come K(R nero) e k(r bianco)
    std::string stringa_per_mappa();
    
    //metodo che controlla che il giocatore del colore passatto per parametro non sia in stallo
    bool stallo(Pezzo::Colore colore);

    //gestione mappa per salvataggio delle scacchiere per patta posizione
    void inserisci_scacchiera();
    int get_ripetizioni_scacchiera();
    
    //metodi che ritornano tutti i pezzi ancora in gioco rispettivamente per i pezzi bianchi e neri
    std::vector<Pezzo*> const get_pezzi_bianchi() { return pezzi_bianchi_;}
    std::vector<Pezzo*> const get_pezzi_neri() {return pezzi_neri_;}


    //metodo che verifica se è possibile promuovere qualche pedone e in caso sia possibile
    // chiede al giocatore che con che figura vuole promuoverlo ed elimina il pedone
    int promuovi(Casella pos_pedone);

    // seconda fase della promozione in cui il pezzo scelto per la promozione viene passao
    // assieme al colore del giocatore e la colonna alla quale era il pezzo da promuovere
    void fine_promozione(char pezzo_scelto, Pezzo::Colore colore, int colonna_promozione);
    
    // Metodo che ritorna sotto forma di stringa il log delle mosse effettuate
    std::string log_mosse();

  private:
    //matrice che contiene i puntatori ai singoli pezzi e rappresenta la scacchiera
    //posizione in matrice -> posizione scacchiera - 1 (sia per riga che per colonna)
    Pezzo* scacchiera[RIGHE][COLONNE]; 

    //vector contenente i puntatori a tutti i pezzi ancora presenti nella scacchiera
    std::vector<Pezzo*> pezzi_neri_;
    std::vector<Pezzo*> pezzi_bianchi_;

    //puntatori ai due re (servono nello scacco)
    Pezzo* re_nero_;
    Pezzo* re_bianco_;

    //contatore delle mosse in cui non si muove un pedone ne si mangia un pezzo
    int conta_mosse_;

    //contatore delle mosse totali
    int mosse_totali_;

    //mappa per tener conto delle volte in cui una posizione si ripete
    std::map<std::string, int> mappa_posizioni_; 

    //lista contentente le mosse fatte durante tutta la partita
    std::list<std::string> log_mosse_;
};

//HELPER FUNCTION
// overriding operatore << che torna la scacchiera in stringa 
std::ostream& operator<<(std::ostream& os, const Scacchiera& temp);


#endif // SCACCHIERA_H