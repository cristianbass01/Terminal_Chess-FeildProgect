#include "./../include/scacchiera.h"
#include "./../include/regina.h"

Regina::Regina(Casella posizione, Colore colore) {
  posizione_ = posizione;
  colore_ = colore;
  if(colore_ == Colore::nero)
    figura_ = 'D';
  else 
    figura_ = 'd';
}

bool Regina::mossa_valida(Casella posizione_finale, Scacchiera& scacchiera) {
  //calcolo di delta riga e delta colonna
  int delta_riga = posizione_finale.get_riga() - posizione_.get_riga();
  int delta_colonna = posizione_finale.get_colonna() - posizione_.get_colonna();
  
  //verifica che non ci sia una pedina dello stesso colore nella posizione finale
  if(scacchiera.get_casella(posizione_finale) != nullptr)
    if((*(scacchiera.get_casella(posizione_finale))).get_colore() == colore_)
      return false;
  
  //verifico che il movimento ia lungo una riga o lungo una colonna
  if(delta_colonna == 0 || delta_riga == 0){

    //variabile che indica il verso
    int verso;

    //verifico non ci siano pedine nel cammino della regina se si muove lungo la riga
    if(delta_colonna == 0){
      if(delta_riga > 0)
        verso = 1;
      else
        verso = -1;
      for(int i = verso; i < delta_riga - verso ; i += verso){
        if(scacchiera.get_casella(Casella(posizione_.get_riga() + i, posizione_.get_colonna())) != nullptr )
          return false;
      }
    }

    //verifico non ci siano pedine nel cammino della regina se si muove lungo la colonna
    if(delta_riga == 0){
      if(delta_colonna > 0)
        verso = 1;
      else
        verso = -1;
      for(int i = verso; i < delta_colonna - verso ; i += verso){
        if(scacchiera.get_casella(Casella(posizione_.get_riga() , posizione_.get_colonna() + i)) != nullptr )
          return false;
      }
    }
  }
  else{     //verifico che il movimento sia una diagonale, dato che non si muove come una torre
  
    //temp_*** sono variabili temporanee che consentono di determinare di quanto si è spostato 
    //fin adesso la regina
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
    //calcolo del modulo di delta_riga e delta_colonna
    if( delta_colonna < 0)
      delta_colonna *= -1; 
    if( delta_riga < 0)
      delta_riga *= -1;
    //verifica che il movimento sia in diagonale controllando che moduli siano uguali
    if( delta_colonna != delta_riga)
      return false;
  }
  return true;
}