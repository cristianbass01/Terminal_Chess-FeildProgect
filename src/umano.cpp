#include <iostream>

#include "./../include/umano.h"

Umano::Umano(Scacchiera* scacchiera, Pezzo::Colore colore){
  scacchiera_ = scacchiera;
  colore_ = colore;
}

void Umano::gioca(){

  bool done = false; //mossa eseguita correttamente

  static constexpr int a = 97; // per trasformare da lettera a numero di colonna

  while(!done){

    std::cout << std::endl;
    std::cout << "Giocatore ";
    colore_ == Pezzo::Colore::bianco ? std::cout << "bianco (minuscole) " : std::cout << "nero (maiuscole) ";
    std::cout << "(per aiuto HE LP ):" << std::endl;

    //input della mossa
    std::string mossa_1;
    std::cin >> mossa_1;
    std::string mossa_2;
    std::cin >> mossa_2;

    if(mossa_1.size() != 2 || mossa_2.size() != 2)
        std::cout << "Combinazione errata, riprova" << "\n";
    else{
      //tutte lettere in formato minuscolo
       mossa_1[0] = tolower(mossa_1[0]);
       mossa_1[1] = tolower(mossa_1[1]);

       mossa_2[0] = tolower(mossa_2[0]);
       mossa_2[1] = tolower(mossa_2[1]);

      if(mossa_1.compare("he") == 0 && mossa_2.compare("lp") == 0) // Il giocatore vuole vedere le combinazioni disponibili
        combinazioni();
      else if(mossa_1.compare("ff") == 0 && mossa_2.compare("ff") == 0) // Il giocatore vuole terminare la partita
        throw Eccezione("Partita terminata per abbandono giocatore");
      else if(mossa_1.compare("xx") == 0 && mossa_2.compare("xx") == 0)
        scacchiera_->stampa();
      else{
        //creazione colonna iniziale
        int colonna_iniziale = mossa_1[0] - a; // in questo modo parto da a = 0 come colonna
        int riga_iniziale = mossa_1[1] - 49;

        //creazione colonna finale
        int colonna_finale = mossa_2[0] - a; // in questo modo parto da a = 0 come colonna
        int riga_finale = mossa_2[1] - 49;

        try
        {
          Casella iniziale(riga_iniziale, colonna_iniziale); //
          Casella finale(riga_finale, colonna_finale);
          if(scacchiera_->get_casella(iniziale)->get_colore() == colore_){
            done = scacchiera_->mossa(iniziale, finale);
            if(!done)
              std::cout << "Mossa non valida" << std::endl;
            else std::cout << "Mossa eseguita" << std::endl;
          }
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
  std::cout << std::endl;
  std::cout << "***************************************************************" << std::endl;
  std::cout << "*   Le possibili combinazioni di lettere per le mosse sono:   *" << std::endl;
  std::cout << "*   - A1 B2 : per spostare una pedina da A1 a B2              *" << std::endl;
  std::cout << "*   - XX XX : per visualizzare la scacchiera completa         *" << std::endl;
  std::cout << "*   - HE LP : per visualizzare i comandi                      *" << std::endl;
  std::cout << "*   - FF FF : per lasciare il gioco                           *" << std::endl;
  std::cout << "*   Il formato delle lettere non influisce (a = A)            *" << std::endl;
  std::cout << "***************************************************************" << std::endl;
  std::cout << std::endl;
}