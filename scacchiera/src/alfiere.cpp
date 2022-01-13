/*
  Cinel Giovanni 2000147
*/

#include "./../include/scacchiera.h"
#include "./../include/alfiere.h"

Alfiere::Alfiere(Casella posizione, Colore colore) {
  
  //inizializzate variabili membro ereditate da pezzo
  colore_ = colore;
  posizione_ = posizione;

  //inizializzata figura sulla base del colore del pezzo
  if(colore == Colore::nero)
    figura_ = 'A';
  else
    figura_ = 'a';
}

int Alfiere::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera){

  //calcolo di delta riga e delta colonna  (spostamento lungo riga e colonna)
  int delta_riga = posizione_finale.get_riga() - posizione_.get_riga();
  int delta_colonna = posizione_finale.get_colonna() - posizione_.get_colonna();
  
  //verifica che il modulo dello spostamento lungo righe e colonne sia uguale
  //altrimenti la mossa non è valida per l'alfiere
  if(abs(delta_riga) != abs(delta_colonna))
    return false;
  
  //verifica che non ci sia una pedina dello stesso colore nella posizione finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;
  
  //temp_driga e temp_dcolonna sono variabili temporanee utilizzate per il controllo 
  //delle caselle nella diagonale descritta dalla casella di partenza e quella di arrivo
  int temp_driga;
  int temp_dcolonna;
  
  //imposto le variabili temp_driga e temp_dcolonna per verificare che le caselle nella
  //diagonale descritta dalla casella di partenza e quella di arrivo siano libere, ricordandomi
  //che la verifica parte dalla casella adiacente a quella di arrivo, perchè la casella di arrivo 
  //è gia stata controllata 
  if(delta_riga > 0)
    temp_driga = delta_riga -1;
  else
    temp_driga = delta_riga +1;
  if(delta_colonna > 0)
    temp_dcolonna = delta_colonna -1;
  else
    temp_dcolonna = delta_colonna +1;

  //Casella temporanea utilizzata per controllare che le posizioni
  //nella diagonale tra posizione finale e inziale siano libere
  Casella temp_casella(0,0);

  //verifica che le posizioni nella diagonale tra posizione finale e inziale siano libere
  //partendo dalla casella adiacente a quella di arrivo fino a quella adiacente a quella di partenza
  while(temp_dcolonna != 0 && temp_driga != 0){

    //imposto i valori della riga e della colonna per il controllo
    temp_casella.set_colonna(posizione_.get_colonna() + temp_dcolonna);
    temp_casella.set_riga(posizione_.get_riga() + temp_driga);

    //verifica che non ci siauna pedina nella casella
    if(scacchiera.get_casella(temp_casella) != nullptr )
      return false;
    
    //aggiorno le variabili temp_driga e temp_dcolonna seguendo il verso in cui si muove l'alfieere
    if(temp_driga > 0)
      temp_driga--;
    else
      temp_driga++;
    if(temp_dcolonna > 0)
      temp_dcolonna--;
    else
      temp_dcolonna++;
  }
  return true;
}
