# Terminal Chess

Progetto realizzato da Feild_progect:
- Bassotto Cristian
- Cinel Giovanni
- Nordio Gianluca

Sui file scacchiera.h e scacchiera.cpp abbiamo scritto i nomi di tutti i componenti dato che il contributo nei citati file è stato uguale da parte di tutti.
In generale nel progetto il lavoro è stato ripartito con equità tra i componenti del gruppo.

Inoltre il programma risulta funzionare al 100% e non presenta alcuna parte mancante.

Stile seguito: https://google.github.io/styleguide/cppguide.html

Per quanto riguarda il giocatore contro computer abbiamo deciso di inserire i seguenti comandi.

Le possibili combinazioni di lettere per le mosse sono:
- A1 B2 : per spostare una pedina da A1 a B2           
- A1 B2 PP: per spostare una pedina da A1 a B2 e chiedere patta all'altro giocatore       
- A1 MM : per visualizzare le mosse disponibili per A1 
- XX XX : per visualizzare la scacchiera completa      
- HE LP : per visualizzare i comandi                   
- FF FF : per lasciare il gioco                        
Il formato delle lettere non influisce (a = A)

Questo messaggio è anche visualizzabile all'interno del programma scrivendo HE LP.

Il programma verifica che siano rispettate e rispetta in ogni caso le regole di scacchi ufficiali e indicate nei seguenti siti:
- https://www.scuolascacchipordenone.eu/le-regole.html 
- https://www.scuolascacchipordenone.eu/le-mosse-speciali-.html
- https://www.scuolascacchipordenone.eu/scacco-scaccomatto-patta-.html

## Compilare l'eseguibile
Scaricare il file scacchi_definitivo.zip

Requisiti:
- cmake

Con CMake
1) Andare sulla cartella Feild_Progect e da terminale $cmake -S . -B ./build
2) Entrare su build ($ cd build)
3) Compilare con $ make

## Lanciare l'eseguibile
4) Eseguire $ ./Feild_Progect

## Descrizione iniziale progetto
![Assegnamento_scacchiera_Pagina_1](https://user-images.githubusercontent.com/72708597/210579828-b075a0f8-8f02-408f-95d3-41b63e83e32d.jpg)
![Assegnamento_scacchiera_Pagina_2](https://user-images.githubusercontent.com/72708597/210579850-ac9de2d6-83c4-42b5-a0ec-620f2c138fbb.jpg)
![Assegnamento_scacchiera_Pagina_3](https://user-images.githubusercontent.com/72708597/210579859-e0d8192c-3949-459f-b859-9598a30cb5d3.jpg)
![Assegnamento_scacchiera_Pagina_4](https://user-images.githubusercontent.com/72708597/210579871-e75570b1-f158-4705-97d5-b480306b3b58.jpg)
