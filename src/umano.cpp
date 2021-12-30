#include <iostream>

#include "./../include/umano.h"

Umano::Umano(Scacchiera* scacchiera, Pezzo::Colore colore){
  scacchiera_ = scacchiera;
  colore_ = colore;
}

void Umano::gioca(){
  std::string mossa;
  bool done = false;

  static constexpr int a = 97; // per trasformare da lettera a numero di colonna

  while(!done){

    std::cout << "Inserisci mossa (per i formati possibili HE LP ): " << std::endl;

    //creo la stringa completa della mossa
    std::string tmp;
    std::cin >> tmp;
    mossa = tmp;
    std::cin >> tmp;
    mossa += " " + tmp;

    if(mossa.size() != 5 || mossa[2] != ' ')
        std::cout << "Combinazione errata, riprova" << "\n";
    else{
      //tutte lettere in formato minuscolo
      for(int i = 0; i < mossa.size(); i++)
        mossa[i] = std::tolower(mossa[i]);

      if(mossa.compare("he lp") == 0) // Il giocatore vuole vedere le combinazioni disponibili
        combinazioni();
      else if(mossa.compare("ff ff") == 0) // Il giocatore vuole terminare la partita
        throw Eccezione("Partita terminata per abbandono giocatore");
      else{
        //creazione colonna iniziale
        int colonna_iniziale = mossa[0] - a; // in questo modo parto da a = 0 come colonna
        int riga_iniziale = mossa[1];

        //creazione colonna finale
        int colonna_finale = mossa[3] - a; // in questo modo parto da a = 0 come colonna
        int riga_finale = mossa[4];

        try
        {
          Casella iniziale(riga_iniziale, colonna_iniziale); //
          Casella finale(riga_finale, colonna_finale);
          if(scacchiera_->get_casella(iniziale)->get_colore() == colore_)
            done = scacchiera_->mossa(iniziale, finale);
          else
            throw Eccezione("[Eccezione::PezzoErrato] Il pezzo che vuoi muovere è di un colore diverso dal tuo");
        }
        catch(Eccezione e) // casella errata o mossa non valida
        {
          std::cout<< e.errore() << '\n';
        }
      }
    }
  }
}

void Umano::combinazioni(){
  std::cout << "***************************************************************" << "\n";
  std::cout << "*   Le possibili combinazioni di lettere per le mosse sono:   *" << "\n";
  std::cout << "*   - A1 B2 : per spostare una pedina da A1 a B2              *" << "\n";
  std::cout << "*   - XX XX : per visualizzare la scacchiera completa         *" << "\n";
  std::cout << "*   - HE LP : per visualizzare i comandi                      *" << "\n";
  std::cout << "*   - FF FF : per lasciare il gioco                           *" << "\n";
  std::cout << "*   Il formato delle lettere non influisce (a = A)            *" << "\n";
  std::cout << "***************************************************************" << "\n";
}