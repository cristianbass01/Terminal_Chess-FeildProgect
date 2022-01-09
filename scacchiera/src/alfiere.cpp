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
  //calcolo di delta riga e delta colonna
  int delta_riga = posizione_finale.get_riga() - posizione_.get_riga();
  int delta_colonna = posizione_finale.get_colonna() - posizione_.get_colonna();
  
  //se la differenza di righe e colonne è diversa sicuramente non è una mossa valida 
  if(abs(delta_riga) != abs(delta_colonna))
    return false;
  
  //verifica che non ci sia una pedina dello stesso colore nella posizione finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;
  
  //temp_*** sono variabili temporanee che consentono di determinare di quanto si è spostato 
  //fin adesso l'alfiere
  int temp_driga;
  int temp_dcolonna;
  
  //rimozione ultima casella da temp_d***
  if(delta_riga > 0)
    temp_driga = delta_riga -1;
  else
    temp_driga = delta_riga +1;
  if(delta_colonna > 0)
    temp_dcolonna = delta_colonna -1;
  else
    temp_dcolonna = delta_colonna +1;

  //verifica che le posizioni in diagonale tra posizione finale e inziale siano libere
  Casella temp_casella(0,0);
  while(temp_dcolonna != 0 && temp_driga != 0){
    //crea una casella (richiesto per poter utilizzare scacchiera.get_casella())
    temp_casella.set_colonna(posizione_.get_colonna() + temp_dcolonna);
    temp_casella.set_riga(posizione_.get_riga() + temp_driga);
    //verifica che non ci siano pedine in mezzo alla diagonale di movimento
    if(scacchiera.get_casella(temp_casella) != nullptr )
      return false;
    
    //modifica temp_d*** a seconda del verso in cui ci si muove
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
